
// MFCZongHe1View.cpp : CMFCZongHe1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCZongHe1.h"
#endif

#include "MFCZongHe1Set.h"
#include "MFCZongHe1Doc.h"
#include "MFCZongHe1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCZongHe1View

IMPLEMENT_DYNCREATE(CMFCZongHe1View, CRecordView)

BEGIN_MESSAGE_MAP(CMFCZongHe1View, CRecordView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCZongHe1View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CMFCZongHe1View 构造/析构

CMFCZongHe1View::CMFCZongHe1View()
	: CRecordView(CMFCZongHe1View::IDD)
	, name(_T(""))
	, id(_T(""))
	, path(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CMFCZongHe1View::~CMFCZongHe1View()
{
}

void CMFCZongHe1View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_2);
}

BOOL CMFCZongHe1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFCZongHe1View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCZongHe1Set;
	CRecordView::OnInitialUpdate();

}

void CMFCZongHe1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCZongHe1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCZongHe1View 诊断

#ifdef _DEBUG
void CMFCZongHe1View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCZongHe1View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCZongHe1Doc* CMFCZongHe1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCZongHe1Doc)));
	return (CMFCZongHe1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCZongHe1View 数据库支持
CRecordset* CMFCZongHe1View::OnGetRecordset()
{
	return m_pSet;
}



// CMFCZongHe1View 消息处理程序
void CMFCZongHe1View::draw(CString file)
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

void CMFCZongHe1View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString filename;
	filename = m_pSet->m_3;
	draw(filename);
}
