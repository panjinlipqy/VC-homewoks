
// MFCtext3(2)View.cpp : CMFCtext32View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtext3(2).h"
#endif

#include "MFCtext3(2)Doc.h"
#include "MFCtext3(2)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext32View

IMPLEMENT_DYNCREATE(CMFCtext32View, CView)

BEGIN_MESSAGE_MAP(CMFCtext32View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCtext32View 构造/析构

CMFCtext32View::CMFCtext32View()
{
	// TODO: 在此处添加构造代码
}

CMFCtext32View::~CMFCtext32View()
{
}

BOOL CMFCtext32View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtext32View 绘制

void CMFCtext32View::OnDraw(CDC* pDC)
{
	CMFCtext32Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	for(int i = 0; i < pDoc->ca.GetSize(); i++)
	   pDC->Ellipse(pDoc->ca.GetAt(i));
}

void CMFCtext32View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext32View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext32View 诊断

#ifdef _DEBUG
void CMFCtext32View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext32View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext32Doc* CMFCtext32View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext32Doc)));
	return (CMFCtext32Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext32View 消息处理程序


void CMFCtext32View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	r = rand() % 50 + 5;
	r2 = rand()%50+3;
	CRect cr(point.x-r, point.y-r2, point.x+r, point.y+r2);
	
	CMFCtext32Doc* pDoc = GetDocument();
	pDoc->ca.Add(cr);
	this->Invalidate();

	//CClientDC dc(this);
	//dc.Ellipse(cr);
	CView::OnLButtonDown(nFlags, point);
}
