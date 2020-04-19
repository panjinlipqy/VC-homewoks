
// MFCtext3View.cpp : CMFCtext3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtext3.h"
#endif

#include "MFCtext3Doc.h"
#include "MFCtext3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext3View

IMPLEMENT_DYNCREATE(CMFCtext3View, CView)

BEGIN_MESSAGE_MAP(CMFCtext3View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCtext3View 构造/析构

CMFCtext3View::CMFCtext3View()
{
	// TODO: 在此处添加构造代码

}

CMFCtext3View::~CMFCtext3View()
{
}

BOOL CMFCtext3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtext3View 绘制

void CMFCtext3View::OnDraw(CDC* pDC)
{
	CMFCtext3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(cr);
	
	// TODO: 在此处为本机数据添加绘制代码
	
}

void CMFCtext3View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext3View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext3View 诊断

#ifdef _DEBUG
void CMFCtext3View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext3Doc* CMFCtext3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext3Doc)));
	return (CMFCtext3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext3View 消息处理程序


void CMFCtext3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	this->GetClientRect(&cr);
	if((cr.bottom - cr.top) >= (cr.right - cr.left)){
		int n = (cr.bottom - (cr.right - cr.left))/2;
		cr.bottom = cr.bottom - n;
	    cr.top = cr.top + n;
	}
	else{
		int m = (cr.right-(cr.bottom - cr.top))/2;
		cr.right = cr.right - m;
		cr.left = cr.left + m;
	}
	this->Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
