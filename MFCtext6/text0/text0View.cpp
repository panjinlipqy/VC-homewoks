
// text0View.cpp : Ctext0View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// Ctext0View ����/����

Ctext0View::Ctext0View()
{
	// TODO: �ڴ˴���ӹ������
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
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Ctext0View ����

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
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
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


// Ctext0View ���

#ifdef _DEBUG
void Ctext0View::AssertValid() const
{
	CView::AssertValid();
}

void Ctext0View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctext0Doc* Ctext0View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctext0Doc)));
	return (Ctext0Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctext0View ��Ϣ�������

void Ctext0View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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


