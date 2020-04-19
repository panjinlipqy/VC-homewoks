
// MFCtext5View.cpp : CMFCtext5View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtext5.h"
#endif

#include "MFCtext5Doc.h"
#include "MFCtext5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext5View

IMPLEMENT_DYNCREATE(CMFCtext5View, CView)

BEGIN_MESSAGE_MAP(CMFCtext5View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFCtext5View 构造/析构

CMFCtext5View::CMFCtext5View()
{
	// TODO: 在此处添加构造代码

}

CMFCtext5View::~CMFCtext5View()
{
}

BOOL CMFCtext5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtext5View 绘制

void CMFCtext5View::OnDraw(CDC* pDC)
{
	CMFCtext5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->t);
}

void CMFCtext5View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext5View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext5View 诊断

#ifdef _DEBUG
void CMFCtext5View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext5Doc* CMFCtext5View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext5Doc)));
	return (CMFCtext5Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext5View 消息处理程序


void CMFCtext5View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCtext5Doc* pDoc = GetDocument();
	
	pDoc->p2 = point;
	CClientDC clientDC(this);
	/*char s[20];
	wsprintf(s, "X=%d  Y=%d   ", pDoc->p2.x, pDoc->p2.y);
	clientDC.TextOut(pDoc->p2.x, pDoc->p2.y, s);*/

	CView::OnLButtonDown(nFlags, point);
}


void CMFCtext5View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCtext5Doc* pDoc = GetDocument();
	CClientDC clientDC(this);
	char s[20];
	wsprintf(s, "X=%d  Y=%d   ", point.x, point.y);
	clientDC.TextOut(20, 20, s);

	CView::OnMouseMove(nFlags, point);
}


void CMFCtext5View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCtext5Doc* pDoc = GetDocument();

		pDoc->p1 = point;
		CClientDC clientDC(this);

	/*char s[20];
	wsprintf(s, "X=%d  Y=%d   ", pDoc->p1.x, pDoc->p1.y);
	clientDC.TextOut(pDoc->p1.x, pDoc->p1.y, s);*/

		pDoc->t.top = pDoc->p1.y; pDoc->t.bottom = pDoc->p2.y;
	    pDoc->t.left = pDoc->p1.x; pDoc->t.right = pDoc->p2.x;

		InvalidateRect(NULL, FALSE);
	CView::OnLButtonUp(nFlags, point);
}
