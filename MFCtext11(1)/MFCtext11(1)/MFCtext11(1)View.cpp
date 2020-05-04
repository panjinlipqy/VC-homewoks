
// MFCtext11(1)View.cpp : CMFCtext111View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCtext11(1).h"
#endif

#include "MFCtext11(1)Doc.h"
#include "MFCtext11(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext111View

IMPLEMENT_DYNCREATE(CMFCtext111View, CView)

BEGIN_MESSAGE_MAP(CMFCtext111View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFCtext111View ����/����

CMFCtext111View::CMFCtext111View()
{
	// TODO: �ڴ˴���ӹ������
	r.top = 10;
	r.left = 10;
	r.bottom = 70;
	r.right = 70;
	//p.x = r.left;
	//p.y = r.top;
	x = 0;
	y = 0;
	Flag =0;
}

CMFCtext111View::~CMFCtext111View()
{
}

BOOL CMFCtext111View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCtext111View ����

void CMFCtext111View::OnDraw(CDC* pDC)
{
	CMFCtext111Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(r);
}

void CMFCtext111View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext111View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext111View ���

#ifdef _DEBUG
void CMFCtext111View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext111View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext111Doc* CMFCtext111View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext111Doc)));
	return (CMFCtext111Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext111View ��Ϣ�������


void CMFCtext111View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	if(point.x >= r.left && point.x <= r.right && point.y >= r.top && point.y <= r.bottom){
		p = point;
		Flag = 1;
	}
	CView::OnLButtonDown(nFlags, point);
}


void CMFCtext111View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CRect R;
	GetClientRect(R);
	if(Flag){
	x = point.x - p.x;
	y = point.y - p.y;
	r.left += x;
	r.right+=x;
	r.top += y;
	r.bottom+= y;
	p = point;
	}
	Invalidate();
	CView::OnMouseMove(nFlags, point);
}


void CMFCtext111View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Flag =0;

	CView::OnLButtonUp(nFlags, point);
}
