
// MFCtext4(2)View.cpp : CMFCtext42View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtext4(2).h"
#endif

#include "MFCtext4(2)Doc.h"
#include "MFCtext4(2)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext42View

IMPLEMENT_DYNCREATE(CMFCtext42View, CView)

BEGIN_MESSAGE_MAP(CMFCtext42View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCtext42View 构造/析构

CMFCtext42View::CMFCtext42View()
{
	// TODO: 在此处添加构造代码

}

CMFCtext42View::~CMFCtext42View()
{
}

BOOL CMFCtext42View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtext42View 绘制

void CMFCtext42View::OnDraw(CDC* pDC)
{
	CMFCtext42Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

}

void CMFCtext42View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext42View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext42View 诊断

#ifdef _DEBUG
void CMFCtext42View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext42View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext42Doc* CMFCtext42View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext42Doc)));
	return (CMFCtext42Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext42View 消息处理程序


void CMFCtext42View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCtext42Doc* pDoc = GetDocument();
	CClientDC dc(this);
	dc.TextOutW(200,200, pDoc->s3);
	CView::OnLButtonDown(nFlags, point);
}
