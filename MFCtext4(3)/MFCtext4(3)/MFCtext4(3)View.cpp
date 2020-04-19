
// MFCtext4(3)View.cpp : CMFCtext43View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCtext4(3).h"
#endif

#include "MFCtext4(3)Doc.h"
#include "MFCtext4(3)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext43View

IMPLEMENT_DYNCREATE(CMFCtext43View, CView)

BEGIN_MESSAGE_MAP(CMFCtext43View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCtext43View ����/����

CMFCtext43View::CMFCtext43View()
{
	// TODO: �ڴ˴���ӹ������
	count = -1;
	s3.Format(_T("%d"), c);
	s4 = "�����Ч";
	f1="+";
	f2="-";
	f3="��";
	f4="��";

}

CMFCtext43View::~CMFCtext43View()
{
}

BOOL CMFCtext43View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCtext43View ����

void CMFCtext43View::OnDraw(CDC* pDC)
{
	CMFCtext43Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CRect A(100,100,300,300);
	CRect B(350,300,500,500);
	CRect C(900,200,1200,500);
	CRect D(1000,10,1200,200);

	pDC->Rectangle(A);
	pDC->Rectangle(B);
	pDC->Rectangle(C);
	pDC->Rectangle(D);
}

void CMFCtext43View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext43View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext43View ���

#ifdef _DEBUG
void CMFCtext43View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext43View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext43Doc* CMFCtext43View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext43Doc)));
	return (CMFCtext43Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext43View ��Ϣ�������


void CMFCtext43View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	if(point.x > 100 && point.x < 300 && point.y < 300 && point.y > 100)
	{
		a = rand() % 10 + 1;
		s1.Format(_T("%d"), a);
		dc.TextOut(point.x, point.y, s1);
	}
	else if(point.x > 350 && point.x < 500 && point.y < 500 && point.y > 300)
	{
		b =rand() % 20 + 3;
	    s2.Format(_T("%d"), b);
		dc.TextOut(point.x, point.y, s2);
	}
	else if(point.x > 900 && point.x < 1200 && point.y < 500 && point.y > 200) ;
	else if(point.x > 1000 && point.x < 1200 && point.y < 200 && point.y > 10) 
	{
		count++;
		if(count%4==0)dc.TextOut(point.x, point.y, f1);
		if(count%4==1)dc.TextOut(point.x, point.y, f2);
		if(count%4==2)dc.TextOut(point.x, point.y, f3);
		if(count%4==3)dc.TextOut(point.x, point.y, f4);
	}
	else dc.TextOut(point.x, point.y, s4);

	
	CView::OnLButtonDown(nFlags, point);
}


void CMFCtext43View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	if((point.x > 900 && point.x < 1200 && point.y < 500 && point.y > 200))
	{
		if(count == -1) c = a+b;
		if(count%4==0) c = a+b;
		if(count%4==1) c = a-b;
		if(count%4==2) c = a*b;
		if(count%4==3) c = a/b;
		s3.Format(_T("%d"), c);
		dc.TextOut(point.x, point.y, s3);
	}
	CView::OnRButtonDown(nFlags, point);
}
