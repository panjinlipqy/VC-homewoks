
// MFCCtext1(2)View.cpp : CMFCCtext12View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCCtext1(2).h"
#endif

#include "MFCCtext1(2)Doc.h"
#include "MFCCtext1(2)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCCtext12View

IMPLEMENT_DYNCREATE(CMFCCtext12View, CView)

BEGIN_MESSAGE_MAP(CMFCCtext12View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCCtext12View 构造/析构

CMFCCtext12View::CMFCCtext12View()
{
	// TODO: 在此处添加构造代码
	r.bottom = 0;
	r.top = 0;
	r.left = 0;
	r.right = 0;
}

CMFCCtext12View::~CMFCCtext12View()
{
}

BOOL CMFCCtext12View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCCtext12View 绘制

void CMFCCtext12View::OnDraw(CDC* pDC)
{
	CMFCCtext12Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Ellipse(r);
	
}

void CMFCCtext12View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCCtext12View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCCtext12View 诊断

#ifdef _DEBUG
void CMFCCtext12View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCCtext12View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCCtext12Doc* CMFCCtext12View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCCtext12Doc)));
	return (CMFCCtext12Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCCtext12View 消息处理程序


void CMFCCtext12View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int a = rand()%70+4;
	//CClientDC dc(this);
	
	r.bottom = point.y + a;
	r.top = point.y - a;
	r.left = point.x - a;
	r.right = point.x + a;
	//dc.Ellipse(r);
	Invalidate();
	
	CView::OnLButtonDown(nFlags, point);
}
