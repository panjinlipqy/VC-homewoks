
// MFCtext14实验1View.cpp : CMFCtext14实验1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtext14实验1.h"
#endif

#include "MFCtext14实验1Doc.h"
#include "MFCtext14实验1View.h"
#include "MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext14实验1View

IMPLEMENT_DYNCREATE(CMFCtext14实验1View, CView)

BEGIN_MESSAGE_MAP(CMFCtext14实验1View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	
END_MESSAGE_MAP()

// CMFCtext14实验1View 构造/析构

CMFCtext14实验1View::CMFCtext14实验1View()
{
	// TODO: 在此处添加构造代码

}

CMFCtext14实验1View::~CMFCtext14实验1View()
{
}

BOOL CMFCtext14实验1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtext14实验1View 绘制

void CMFCtext14实验1View::OnDraw(CDC* /*pDC*/)
{
	CMFCtext14实验1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFCtext14实验1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext14实验1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext14实验1View 诊断

#ifdef _DEBUG
void CMFCtext14实验1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext14实验1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext14实验1Doc* CMFCtext14实验1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext14实验1Doc)));
	return (CMFCtext14实验1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext14实验1View 消息处理程序


void CMFCtext14实验1View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	MyDlg md2;
	int r = md2.DoModal();
	if(r==IDOK)
	{
		//CString s1=md2.s;
		//GetDC()->TextOutW(100, 100, s1);
	}
	CView::OnLButtonDblClk(nFlags, point);
}



