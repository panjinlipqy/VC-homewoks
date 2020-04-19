
// text0View.cpp : Ctext0View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "text0.h"
#endif

#include "text0Doc.h"
#include "text0View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctext0View

IMPLEMENT_DYNCREATE(Ctext0View, CView)

BEGIN_MESSAGE_MAP(Ctext0View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// Ctext0View 构造/析构

Ctext0View::Ctext0View()
{
	// TODO: 在此处添加构造代码
	set = true;
	N = 5;
	for(int i = 0; i< N; i++)
	{
		int t = (i+1) * 100;
		CRect rect(t, 0, t+20, 20);
		cr.Add(rect);
		y.Add(2);
	}
	r.left = 30;
	r.top = 30;
	r.right = 700;
	r.bottom = 700;

}

Ctext0View::~Ctext0View()
{
}

BOOL Ctext0View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ctext0View 绘制

void Ctext0View::OnDraw(CDC* pDC)
{
	Ctext0Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	
	GetWindowRect(&rect);
	GetClientRect(&rect);

	if(set)
	{
		for(int i =0; i < N; i++)
		{
			SetTimer(i, rand()%400+100, NULL);
		}	
		set = false;
	}
	// TODO: 在此处为本机数据添加绘制代码
	for(int i =0; i < N; i++)
	{
		pDC->Ellipse(cr[i]);
	}

	//pDC->Rectangle(rect);

}

void Ctext0View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Ctext0View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Ctext0View 诊断

#ifdef _DEBUG
void Ctext0View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext0View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext0Doc* Ctext0View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext0Doc)));
	return (Ctext0Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext0View 消息处理程序

void Ctext0View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int i = nIDEvent;
	

	if(y[i] < rect.bottom){
	   cr[i].top += 50;
	   cr[i].bottom += 50;
	   if(cr[i].bottom >= rect.bottom){
		   y[i] = rect.bottom;
	   }
	}else if(y[i] >= rect.bottom){
		cr[i].top -= 50;
		cr[i].bottom -= 50;
		//cr[i].top = rect.bottom - 20;
		//cr[i].bottom = rect.bottom;

		if(cr[i].top < 0){
		
		  y[i] = 2;
	   }
	 }
	Invalidate();

	

	/*if(){
		cr[i].top = rect.bottom;
		
	     }*/

	

	CView::OnTimer(nIDEvent);
}


