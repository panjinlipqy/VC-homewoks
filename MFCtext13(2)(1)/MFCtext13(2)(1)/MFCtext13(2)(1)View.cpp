
// MFCtext13(2)(1)View.cpp : CMFCtext1321View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtext13(2)(1).h"
#endif

#include "MFCtext13(2)(1)Doc.h"
#include "MFCtext13(2)(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext1321View

IMPLEMENT_DYNCREATE(CMFCtext1321View, CView)

BEGIN_MESSAGE_MAP(CMFCtext1321View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_TIMER()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCtext1321View 构造/析构

CMFCtext1321View::CMFCtext1321View()
{
	// TODO: 在此处添加构造代码
	re.bottom = 0;
	re.top = 0;
	re.left = 0;
	re.right = 0;
	rs.bottom = 0;
	rs.top = 0;
	rs.right = 0;
	rs.left = 0;
	flag = 0;
	pe.x= 0;
	pe.y=0;
	pt.x=0;
	pt.y = 0;
	ps.x= 0;
	ps.y =0;

}

CMFCtext1321View::~CMFCtext1321View()
{
}

BOOL CMFCtext1321View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtext1321View 绘制

void CMFCtext1321View::OnDraw(CDC* pDC)
{
	CMFCtext1321Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if(set)
	{
		
			SetTimer(0, rand()%400+100, NULL);
		     set = false;
	}
	pDC->Ellipse(rs);
	// TODO: 在此处为本机数据添加绘制代码
}

void CMFCtext1321View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext1321View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext1321View 诊断

#ifdef _DEBUG
void CMFCtext1321View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext1321View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext1321Doc* CMFCtext1321View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext1321Doc)));
	return (CMFCtext1321Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext1321View 消息处理程序


void CMFCtext1321View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(flag == 0) {
    pe.x= 0;
	pe.y=0;
	pt.x=0;
	pt.y = 0;
	ps.x= 0;
	ps.y =0;

	}
	ps = point;
	flag = 1;
	//Invalidate();
	CView::OnLButtonDown(nFlags, point);
}


void CMFCtext1321View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	pe = pt;
	flag = 0;
	CView::OnLButtonUp(nFlags, point);
}


void CMFCtext1321View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	rs.left = ps.x;
	rs.top = ps.y;
	if(rs.right < pt.x && pe.x == 0) rs.right = pt.x;
	else if(pe.x != 0) rs.right = pe.x;

	if(rs.bottom < pt.y && pe.y == 0) rs.bottom = pt.y;
	else if (pe.y != 0) rs.bottom = pe.y;
	Invalidate();
	CView::OnTimer(nIDEvent);
}


void CMFCtext1321View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (flag == 1)
	pt = point;
	CView::OnMouseMove(nFlags, point);
}
