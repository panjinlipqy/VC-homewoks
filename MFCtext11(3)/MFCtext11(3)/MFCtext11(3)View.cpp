
// MFCtext11(3)View.cpp : CMFCtext113View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtext11(3).h"
#endif

#include "MFCtext11(3)Doc.h"
#include "MFCtext11(3)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext113View

IMPLEMENT_DYNCREATE(CMFCtext113View, CView)

BEGIN_MESSAGE_MAP(CMFCtext113View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFCtext113View 构造/析构

CMFCtext113View::CMFCtext113View()
{
	// TODO: 在此处添加构造代码
	set = true;
	r.left =0;
	r.top = 30;
	r.right = 70;
	r.bottom = 100;
	x1 = 0;
	x2 = 0;

	flag = 0;
}

CMFCtext113View::~CMFCtext113View()
{
}

BOOL CMFCtext113View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtext113View 绘制

void CMFCtext113View::OnDraw(CDC* pDC)
{
	CMFCtext113Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	GetClientRect(&rect);
	//r.left = rect.right /2 - 35;
	//r.right = 35 + rect.right /2;


	if(set)
	{
			SetTimer(0, rand()%400+100, NULL);
		set = false;
	}
	pDC->Ellipse(r);
}

void CMFCtext113View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext113View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext113View 诊断

#ifdef _DEBUG
void CMFCtext113View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext113View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext113Doc* CMFCtext113View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext113Doc)));
	return (CMFCtext113Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext113View 消息处理程序


void CMFCtext113View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flag = 1;

	CView::OnLButtonDown(nFlags, point);
}


void CMFCtext113View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flag = 2;
	CView::OnLButtonDblClk(nFlags, point);
}


void CMFCtext113View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int i = nIDEvent;
	if(flag == 1){
		if((r.right <= rect.right || r.left <= 0) && x2 != 1){
		r.left += 20;
		r.right += 20;
		if(r.right >= rect.right ) x2 = 1;
	}else if(x2 >= rect.right || x2 == 1){
		r.right -= 20;
		r.left -= 20;
		if(r.left <= 0)  x2 = 3;
	}
	}else if(flag == 2){
		r.left = r.left;
		r.right = r.right;
	}
	
	Invalidate();
	CView::OnTimer(nIDEvent);
}
