
// MFCtext7(1)View.cpp : CMFCtext71View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CMFCtext71View ����/����

CMFCtext71View::CMFCtext71View()
{
	// TODO: �ڴ˴���ӹ������
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
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCtext71View ����

void CMFCtext71View::OnDraw(CDC* pDC)
{
	CMFCtext71Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	
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


// CMFCtext71View ���

#ifdef _DEBUG
void CMFCtext71View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext71View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext71Doc* CMFCtext71View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext71Doc)));
	return (CMFCtext71Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext71View ��Ϣ�������


void CMFCtext71View::OnShow()
{
	// TODO: �ڴ���������������
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
