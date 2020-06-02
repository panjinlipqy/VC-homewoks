
// MFCZongHe1(2)View.cpp : CMFCZongHe12View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCZongHe1(2).h"
#endif

#include "MFCZongHe1(2)Set.h"
#include "MFCZongHe1(2)Doc.h"
#include "MFCZongHe1(2)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCZongHe12View

IMPLEMENT_DYNCREATE(CMFCZongHe12View, CRecordView)

BEGIN_MESSAGE_MAP(CMFCZongHe12View, CRecordView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_RECORD_FIRST, &CMFCZongHe12View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMFCZongHe12View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFCZongHe12View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMFCZongHe12View::OnRecordLast)
END_MESSAGE_MAP()

// CMFCZongHe12View 构造/析构

CMFCZongHe12View::CMFCZongHe12View()
	: CRecordView(CMFCZongHe12View::IDD)
	, name(_T(""))
	, id(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CMFCZongHe12View::~CMFCZongHe12View()
{
}

void CMFCZongHe12View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_2);
}

BOOL CMFCZongHe12View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFCZongHe12View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCZongHe12Set;
	CRecordView::OnInitialUpdate();

}

void CMFCZongHe12View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCZongHe12View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCZongHe12View 诊断

#ifdef _DEBUG
void CMFCZongHe12View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCZongHe12View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCZongHe12Doc* CMFCZongHe12View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCZongHe12Doc)));
	return (CMFCZongHe12Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCZongHe12View 数据库支持
CRecordset* CMFCZongHe12View::OnGetRecordset()
{
	return m_pSet;
}



// CMFCZongHe12View 消息处理程序
void CMFCZongHe12View::draw(CString file)
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

void CMFCZongHe12View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	CString filename;
	filename = m_pSet->m_3;
	draw(filename);
}


void CMFCZongHe12View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if(m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	CString filename;
	filename = m_pSet->m_3;
	draw(filename);
}


void CMFCZongHe12View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if(m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	CString filename;
	filename = m_pSet->m_3;
	draw(filename);
}


void CMFCZongHe12View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	CString filename;
	filename = m_pSet->m_3;
	draw(filename);
}
