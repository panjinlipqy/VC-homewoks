
// MFCtext1(1)View.cpp : CMFCtext11View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtext1(1).h"
#endif

#include "MFCtext1(1)Doc.h"
#include "MFCtext1(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext11View

IMPLEMENT_DYNCREATE(CMFCtext11View, CView)

BEGIN_MESSAGE_MAP(CMFCtext11View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCtext11View 构造/析构

CMFCtext11View::CMFCtext11View()
{
	// TODO: 在此处添加构造代码

}

CMFCtext11View::~CMFCtext11View()
{
}

BOOL CMFCtext11View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtext11View 绘制

void CMFCtext11View::OnDraw(CDC* /*pDC*/)
{
	CMFCtext11Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFCtext11View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext11View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext11View 诊断

#ifdef _DEBUG
void CMFCtext11View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext11View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext11Doc* CMFCtext11View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext11Doc)));
	return (CMFCtext11Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext11View 消息处理程序


void CMFCtext11View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int a = rand()%70+4;
	CClientDC dc(this);
	CRect r;
	r.bottom = point.y + a;
	r.top = point.y - a;
	r.left = point.x - a;
	r.right = point.x + a;
	dc.Ellipse(r);

	CView::OnLButtonDown(nFlags, point);
}
