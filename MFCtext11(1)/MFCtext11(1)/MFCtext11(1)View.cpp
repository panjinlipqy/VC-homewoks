
// MFCtext11(1)View.cpp : CMFCtext111View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtext11(1).h"
#endif

#include "MFCtext11(1)Doc.h"
#include "MFCtext11(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext111View

IMPLEMENT_DYNCREATE(CMFCtext111View, CView)

BEGIN_MESSAGE_MAP(CMFCtext111View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFCtext111View 构造/析构

CMFCtext111View::CMFCtext111View()
{
	// TODO: 在此处添加构造代码
	r.top = 10;
	r.left = 10;
	r.bottom = 70;
	r.right = 70;
	//p.x = r.left;
	//p.y = r.top;
	x = 0;
	y = 0;
	Flag =0;
}

CMFCtext111View::~CMFCtext111View()
{
}

BOOL CMFCtext111View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtext111View 绘制

void CMFCtext111View::OnDraw(CDC* pDC)
{
	CMFCtext111Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(r);
}

void CMFCtext111View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext111View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext111View 诊断

#ifdef _DEBUG
void CMFCtext111View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext111View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext111Doc* CMFCtext111View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext111Doc)));
	return (CMFCtext111Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext111View 消息处理程序


void CMFCtext111View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	if(point.x >= r.left && point.x <= r.right && point.y >= r.top && point.y <= r.bottom){
		p = point;
		Flag = 1;
	}
	CView::OnLButtonDown(nFlags, point);
}


void CMFCtext111View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect R;
	GetClientRect(R);
	if(Flag){
	x = point.x - p.x;
	y = point.y - p.y;
	r.left += x;
	r.right+=x;
	r.top += y;
	r.bottom+= y;
	p = point;
	}
	Invalidate();
	CView::OnMouseMove(nFlags, point);
}


void CMFCtext111View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Flag =0;

	CView::OnLButtonUp(nFlags, point);
}
