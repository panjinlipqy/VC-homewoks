
// MFCtext11(3)View.cpp : CMFCtext113View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCtext11(3).h"
#endif

#include "MFCtext11(3)Doc.h"
#include "MFCtext11(3)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext113View

IMPLEMENT_DYNCREATE(CMFCtext113View, CView)

BEGIN_MESSAGE_MAP(CMFCtext113View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFCtext113View ����/����

CMFCtext113View::CMFCtext113View()
{
	// TODO: �ڴ˴���ӹ������
	set = true;
	r.left =0;
	r.top = 30;
	r.right = 70;
	r.bottom = 100;
	x1 = 0;
	x2 = 0;

	flag = 0;
}

CMFCtext113View::~CMFCtext113View()
{
}

BOOL CMFCtext113View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCtext113View ����

void CMFCtext113View::OnDraw(CDC* pDC)
{
	CMFCtext113Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

	GetClientRect(&rect);
	//r.left = rect.right /2 - 35;
	//r.right = 35 + rect.right /2;


	if(set)
	{
			SetTimer(0, rand()%400+100, NULL);
		set = false;
	}
	pDC->Ellipse(r);
}

void CMFCtext113View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext113View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext113View ���

#ifdef _DEBUG
void CMFCtext113View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext113View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext113Doc* CMFCtext113View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext113Doc)));
	return (CMFCtext113Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext113View ��Ϣ�������


void CMFCtext113View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	flag = 1;

	CView::OnLButtonDown(nFlags, point);
}


void CMFCtext113View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	flag = 2;
	CView::OnLButtonDblClk(nFlags, point);
}


void CMFCtext113View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int i = nIDEvent;
	if(flag == 1){
		if((r.right <= rect.right || r.left <= 0) && x2 != 1){
		r.left += 20;
		r.right += 20;
		if(r.right >= rect.right ) x2 = 1;
	}else if(x2 >= rect.right || x2 == 1){
		r.right -= 20;
		r.left -= 20;
		if(r.left <= 0)  x2 = 3;
	}
	}else if(flag == 2){
		r.left = r.left;
		r.right = r.right;
	}
	
	Invalidate();
	CView::OnTimer(nIDEvent);
}
