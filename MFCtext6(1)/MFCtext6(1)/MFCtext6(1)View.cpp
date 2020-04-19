
// MFCtext6(1)View.cpp : CMFCtext61View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtext6(1).h"
#endif

#include "MFCtext6(1)Doc.h"
#include "MFCtext6(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext61View

IMPLEMENT_DYNCREATE(CMFCtext61View, CView)

BEGIN_MESSAGE_MAP(CMFCtext61View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFCtext61View 构造/析构

CMFCtext61View::CMFCtext61View()
{
	// TODO: 在此处添加构造代码
	count = 0;
	s.Format(_T("%d"),count);

}

CMFCtext61View::~CMFCtext61View()
{

}

BOOL CMFCtext61View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtext61View 绘制

void CMFCtext61View::OnDraw(CDC* /*pDC*/)
{
	CMFCtext61Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFCtext61View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext61View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext61View 诊断

#ifdef _DEBUG
void CMFCtext61View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext61View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext61Doc* CMFCtext61View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext61Doc)));
	return (CMFCtext61Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext61View 消息处理程序


void CMFCtext61View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	// count++;
	// s.Format(_T("%d"),count);
	// s1.Format(_T("%d"),p2.x-p1.x);
	// CClientDC dc(this);
	 //dc.TextOutW(point.x,point.y,s+s1);
	 count++;
	CView::OnMouseMove(nFlags, point);
}


void CMFCtext61View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	 p1 = point;
	 

	CView::OnLButtonDown(nFlags, point);
}


void CMFCtext61View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	p2 = point;
	//if(p1 != p2) count++;
	s.Format(_T("%d"),count);
	s1.Format(_T("%d"),p2.x-p1.x);
	 CClientDC dc(this);
	 dc.TextOutW(point.x,point.y, _T("MOUSEMOVE发生次数:") + s +"    "+"横向移动像素数："+ s1);
	CView::OnLButtonUp(nFlags, point);
}
