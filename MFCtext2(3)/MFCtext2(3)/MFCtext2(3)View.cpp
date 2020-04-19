
// MFCtext2(3)View.cpp : CMFCtext23View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCtext2(3).h"
#endif

#include "MFCtext2(3)Doc.h"
#include "MFCtext2(3)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext23View

IMPLEMENT_DYNCREATE(CMFCtext23View, CView)

BEGIN_MESSAGE_MAP(CMFCtext23View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCtext23View ����/����

CMFCtext23View::CMFCtext23View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCtext23View::~CMFCtext23View()
{
}

BOOL CMFCtext23View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCtext23View ����

void CMFCtext23View::OnDraw(CDC* pDC)
{
	CMFCtext23Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CMFCtext23View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext23View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext23View ���

#ifdef _DEBUG
void CMFCtext23View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext23View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext23Doc* CMFCtext23View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext23Doc)));
	return (CMFCtext23Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext23View ��Ϣ�������


void CMFCtext23View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//(3)
	CClientDC dc(this);
	CMFCtext23Doc* pDoc = GetDocument();
	pDoc->count = pDoc->count + 1;

	CView::OnLButtonDown(nFlags, point);
}


void CMFCtext23View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CMFCtext23Doc* pDoc = GetDocument();
	pDoc->s3.Format(_T("%d"), pDoc->count);
	dc.TextOutW(200,200,pDoc->s3);
	CView::OnRButtonDown(nFlags, point);
}
