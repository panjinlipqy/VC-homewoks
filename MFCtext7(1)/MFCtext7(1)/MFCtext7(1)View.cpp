
// MFCtext7(1)View.cpp : CMFCtext71View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCtext7(1).h"
#endif

#include "MFCtext7(1)Doc.h"
#include "MFCtext7(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext71View

IMPLEMENT_DYNCREATE(CMFCtext71View, CView)

BEGIN_MESSAGE_MAP(CMFCtext71View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_SHOW, &CMFCtext71View::OnShow)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFCtext71View 构造/析构

CMFCtext71View::CMFCtext71View()
{
	// TODO: 在此处添加构造代码
	ca.SetSize(500);
	set = true;
	n1 = 0;
	n2 = 0;
	n3 = 0;
}

CMFCtext71View::~CMFCtext71View()
{
}

BOOL CMFCtext71View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCtext71View 绘制

void CMFCtext71View::OnDraw(CDC* pDC)
{
	CMFCtext71Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	
	//GetWindowRect(&R);
	//GetClientRect(&R);

	if(set)
	{
			SetTimer(0, rand()%400+100, NULL);
		    set = false;
	}

	//for(int i = 0; i < ca.GetSize(); i++)
	COLORREF m_Color(RGB(n1,n2,n3));
	CPen pen(PS_SOLID,1,m_Color);
	pDC->SelectObject(&pen);
		pDC->Ellipse(r);
}

void CMFCtext71View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext71View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext71View 诊断

#ifdef _DEBUG
void CMFCtext71View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext71View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext71Doc* CMFCtext71View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext71Doc)));
	return (CMFCtext71Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext71View 消息处理程序


void CMFCtext71View::OnShow()
{
	// TODO: 在此添加命令处理程序代码
	GetClientRect(&R);
	p.y = (R.bottom + R.top)/2;
	p.x = (R.right + R.left)/2;

	r.left = p.x ;
	r.right = p.x ;
	r.bottom = p.y ;
	r.top = p.y ;
		
	//Invalidate();
}


void CMFCtext71View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int i = nIDEvent;

	if(r.bottom < R.bottom && r.top > 0 && r.left > 0 && r.right < R.right)
	{
		r.left =r.left - 10;
	   r.right = r.right + 10;
	   r.bottom = r.bottom + 10;
	   r.top =r.top - 10;
	}
	else{
		r.left = r.left ;
		r.right =r.right;
		r.bottom =r.bottom;
	    r.top = r.top;
	}
	if(n1<=255)
	n1+=10;
	else n1 = 0;
	if(n2<=255)
	n2+=12;
	else n2=0;
	if(n3<=255)
	n3+=15;
	else n3 = 0;
	Invalidate();
	CView::OnTimer(nIDEvent);
}
