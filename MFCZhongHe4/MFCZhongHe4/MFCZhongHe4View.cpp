
// MFCZhongHe4View.cpp : CMFCZhongHe4View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCZhongHe4.h"
#endif

#include "MFCZhongHe4Set.h"
#include "MFCZhongHe4Doc.h"
#include "MFCZhongHe4View.h"
#include "BigShow.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCZhongHe4View

IMPLEMENT_DYNCREATE(CMFCZhongHe4View, CRecordView)

BEGIN_MESSAGE_MAP(CMFCZhongHe4View, CRecordView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCZhongHe4View::OnBnClickedButton1)
	ON_COMMAND(ID_RECORD_FIRST, &CMFCZhongHe4View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMFCZhongHe4View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFCZhongHe4View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMFCZhongHe4View::OnRecordLast)
END_MESSAGE_MAP()

// CMFCZhongHe4View 构造/析构

CMFCZhongHe4View::CMFCZhongHe4View()
	: CRecordView(CMFCZhongHe4View::IDD)
	, number(_T(""))
	, name(_T(""))
	, sex(_T(""))
	, mon(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CMFCZhongHe4View::~CMFCZhongHe4View()
{
}

void CMFCZhongHe4View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column4);
}

BOOL CMFCZhongHe4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFCZhongHe4View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCZhongHe4Set;
	CRecordView::OnInitialUpdate();

}

void CMFCZhongHe4View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCZhongHe4View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCZhongHe4View 诊断

#ifdef _DEBUG
void CMFCZhongHe4View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCZhongHe4View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCZhongHe4Doc* CMFCZhongHe4View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCZhongHe4Doc)));
	return (CMFCZhongHe4Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCZhongHe4View 数据库支持
CRecordset* CMFCZhongHe4View::OnGetRecordset()
{
	return m_pSet;
}



// CMFCZhongHe4View 消息处理程序
void CMFCZhongHe4View::draw(CString file)
{
	CImage img;
	img.Load(file);
	CDC* pDC = GetDlgItem(IDC_STATIC)->GetDC();
	int sx, sy, w, h;
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);

	float rect_ratio = 1.0*rect.Width() / rect.Height();
		float img_ratio = 1.0*img.GetWidth() / img.GetHeight();  //获取客户区和图片的宽高比

		if(rect_ratio > img_ratio)
		{
			h = rect.Height();
			w = img_ratio*h;
			sx = (rect.Width() - w) /2;
			sy = 0;
		}
		else{
			w = rect.Width();
			h = w / img_ratio;
			sx = 0;
			sy = (rect.Height() - h)/2;
		}
		img.Draw(pDC->m_hDC, sx, sy, w, h);

}

void CMFCZhongHe4View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	BigShow *pd = new BigShow;
	pd->Create(IDD_DIALOG1);
	pd->ShowWindow(1);
	CString file;
	file = m_pSet->column5;
	
	CImage img;
	img.Load(file);
	CDC* pDC = pd->GetDlgItem(IDC_STATIC)->GetDC();
	int sx, sy, w, h;
	CRect rect;
	pd->GetDlgItem(IDC_STATIC)->GetClientRect(&rect);

	float rect_ratio = 1.0*rect.Width() / rect.Height();
		float img_ratio = 1.0*img.GetWidth() / img.GetHeight();  //获取客户区和图片的宽高比

		if(rect_ratio > img_ratio)
		{
			h = rect.Height();
			w = img_ratio*h;
			sx = (rect.Width() - w) /2;
			sy = 0;
			}
		else{
			w = rect.Width();
			h = w / img_ratio;
			sx = 0;
			sy = (rect.Height() - h)/2;
		}
		img.Draw(pDC->m_hDC, sx, sy, w, h);
}


void CMFCZhongHe4View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	CString filename;
	filename = m_pSet->column5;
	draw(filename);
}


void CMFCZhongHe4View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if(m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	CString filename;
	filename = m_pSet->column5;
	draw(filename);
}


void CMFCZhongHe4View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if(m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	CString filename;
	filename = m_pSet->column5;
	draw(filename);
}


void CMFCZhongHe4View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	CString filename;
	filename = m_pSet->column5;
	draw(filename);
}
