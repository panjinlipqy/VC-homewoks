
// MFCtext4View.cpp : CMFCtext4View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtext4.h"
#endif

#include "MFCtext4Doc.h"
#include "MFCtext4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext4View

IMPLEMENT_DYNCREATE(CMFCtext4View, CView)

BEGIN_MESSAGE_MAP(CMFCtext4View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFCtext4View 构造/析构

CMFCtext4View::CMFCtext4View()
{
	// TODO: 在此处添加构造代码

}

CMFCtext4View::~CMFCtext4View()
{
}

BOOL CMFCtext4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtext4View 绘制

void CMFCtext4View::OnDraw(CDC* /*pDC*/)
{
	CMFCtext4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CMFCtext4View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext4View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext4View 诊断

#ifdef _DEBUG
void CMFCtext4View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext4Doc* CMFCtext4View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext4Doc)));
	return (CMFCtext4Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext4View 消息处理程序


void CMFCtext4View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString d= _T("左键正被按下");
	CClientDC dc(this);
	dc.TextOutW(200,200, d);

	CView::OnLButtonDown(nFlags, point);
}


void CMFCtext4View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString u= _T("左键正抬起");
	CClientDC dc(this);
	dc.TextOutW(200,300, u);
	CView::OnLButtonUp(nFlags, point);
}
