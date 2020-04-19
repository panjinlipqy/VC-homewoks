
// MFCtext2(3)View.cpp : CMFCtext23View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtext2(3).h"
#endif

#include "MFCtext2(3)Doc.h"
#include "MFCtext2(3)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext23View

IMPLEMENT_DYNCREATE(CMFCtext23View, CView)

BEGIN_MESSAGE_MAP(CMFCtext23View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCtext23View 构造/析构

CMFCtext23View::CMFCtext23View()
{
	// TODO: 在此处添加构造代码

}

CMFCtext23View::~CMFCtext23View()
{
}

BOOL CMFCtext23View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtext23View 绘制

void CMFCtext23View::OnDraw(CDC* pDC)
{
	CMFCtext23Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFCtext23View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext23View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext23View 诊断

#ifdef _DEBUG
void CMFCtext23View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext23View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext23Doc* CMFCtext23View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext23Doc)));
	return (CMFCtext23Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext23View 消息处理程序


void CMFCtext23View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//(3)
	CClientDC dc(this);
	CMFCtext23Doc* pDoc = GetDocument();
	pDoc->count = pDoc->count + 1;

	CView::OnLButtonDown(nFlags, point);
}


void CMFCtext23View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CMFCtext23Doc* pDoc = GetDocument();
	pDoc->s3.Format(_T("%d"), pDoc->count);
	dc.TextOutW(200,200,pDoc->s3);
	CView::OnRButtonDown(nFlags, point);
}
