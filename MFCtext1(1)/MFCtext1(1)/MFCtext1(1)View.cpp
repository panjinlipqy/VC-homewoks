
// MFCtext1(1)View.cpp : CMFCtext11View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCtext1(1).h"
#endif

#include "MFCtext1(1)Doc.h"
#include "MFCtext1(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext11View

IMPLEMENT_DYNCREATE(CMFCtext11View, CView)

BEGIN_MESSAGE_MAP(CMFCtext11View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCtext11View ����/����

CMFCtext11View::CMFCtext11View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCtext11View::~CMFCtext11View()
{
}

BOOL CMFCtext11View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCtext11View ����

void CMFCtext11View::OnDraw(CDC* /*pDC*/)
{
	CMFCtext11Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CMFCtext11View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext11View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext11View ���

#ifdef _DEBUG
void CMFCtext11View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext11View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext11Doc* CMFCtext11View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext11Doc)));
	return (CMFCtext11Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext11View ��Ϣ�������


void CMFCtext11View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int a = rand()%70+4;
	CClientDC dc(this);
	CRect r;
	r.bottom = point.y + a;
	r.top = point.y - a;
	r.left = point.x - a;
	r.right = point.x + a;
	dc.Ellipse(r);

	CView::OnLButtonDown(nFlags, point);
}
