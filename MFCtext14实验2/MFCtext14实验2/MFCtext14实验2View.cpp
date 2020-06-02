
// MFCtext14实验2View.cpp : CMFCtext14实验2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtext14实验2.h"
#endif

#include "MFCtext14实验2Doc.h"
#include "MFCtext14实验2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext14实验2View

IMPLEMENT_DYNCREATE(CMFCtext14实验2View, CView)

BEGIN_MESSAGE_MAP(CMFCtext14实验2View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFCtext14实验2View 构造/析构

CMFCtext14实验2View::CMFCtext14实验2View()
{
	// TODO: 在此处添加构造代码
	flag = 0;

}

CMFCtext14实验2View::~CMFCtext14实验2View()
{
}

BOOL CMFCtext14实验2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtext14实验2View 绘制

void CMFCtext14实验2View::OnDraw(CDC* pDC)
{
	CMFCtext14实验2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if(set)
	{
		
			SetTimer(0, rand()%400+100, NULL);
		     set = false;
	}

	for(int i = 0; i < pDoc->ca.GetSize(); i++)
	   pDC->Ellipse(pDoc->ca.GetAt(i));
	// TODO: 在此处为本机数据添加绘制代码
}

void CMFCtext14实验2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext14实验2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext14实验2View 诊断

#ifdef _DEBUG
void CMFCtext14实验2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext14实验2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext14实验2Doc* CMFCtext14实验2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext14实验2Doc)));
	return (CMFCtext14实验2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext14实验2View 消息处理程序


void CMFCtext14实验2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flag = 1;
	if(flag==1)
	ps = point;
	CView::OnLButtonDown(nFlags, point);
}


void CMFCtext14实验2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(flag==1)
	pe = point;
	flag = 0;
	
	
	CView::OnLButtonUp(nFlags, point);
}


void CMFCtext14实验2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(flag == 1)
	pe = point;
	CView::OnMouseMove(nFlags, point);
}


void CMFCtext14实验2View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	re.left = ps.x;
	re.top = ps.y;
	re.bottom = pe.y;
	re.right = pe.x;
	CMFCtext14实验2Doc* pDoc = GetDocument();
	CClientDC dc(this);
	if(flag ==0)
	pDoc->ca.Add(re);
	//else dc.Ellipse(re);
	Invalidate();
	CView::OnTimer(nIDEvent);
}
