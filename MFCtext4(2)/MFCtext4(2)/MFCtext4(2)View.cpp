
// MFCtext4(2)View.cpp : CMFCtext42View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCtext4(2).h"
#endif

#include "MFCtext4(2)Doc.h"
#include "MFCtext4(2)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext42View

IMPLEMENT_DYNCREATE(CMFCtext42View, CView)

BEGIN_MESSAGE_MAP(CMFCtext42View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCtext42View ����/����

CMFCtext42View::CMFCtext42View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCtext42View::~CMFCtext42View()
{
}

BOOL CMFCtext42View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCtext42View ����

void CMFCtext42View::OnDraw(CDC* pDC)
{
	CMFCtext42Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

}

void CMFCtext42View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext42View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext42View ���

#ifdef _DEBUG
void CMFCtext42View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext42View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext42Doc* CMFCtext42View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext42Doc)));
	return (CMFCtext42Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext42View ��Ϣ�������


void CMFCtext42View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFCtext42Doc* pDoc = GetDocument();
	CClientDC dc(this);
	dc.TextOutW(200,200, pDoc->s3);
	CView::OnLButtonDown(nFlags, point);
}
