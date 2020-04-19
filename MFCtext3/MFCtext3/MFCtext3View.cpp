
// MFCtext3View.cpp : CMFCtext3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCtext3.h"
#endif

#include "MFCtext3Doc.h"
#include "MFCtext3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext3View

IMPLEMENT_DYNCREATE(CMFCtext3View, CView)

BEGIN_MESSAGE_MAP(CMFCtext3View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCtext3View ����/����

CMFCtext3View::CMFCtext3View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCtext3View::~CMFCtext3View()
{
}

BOOL CMFCtext3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCtext3View ����

void CMFCtext3View::OnDraw(CDC* pDC)
{
	CMFCtext3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(cr);
	
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	
}

void CMFCtext3View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext3View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext3View ���

#ifdef _DEBUG
void CMFCtext3View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext3Doc* CMFCtext3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext3Doc)));
	return (CMFCtext3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext3View ��Ϣ�������


void CMFCtext3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	this->GetClientRect(&cr);
	if((cr.bottom - cr.top) >= (cr.right - cr.left)){
		int n = (cr.bottom - (cr.right - cr.left))/2;
		cr.bottom = cr.bottom - n;
	    cr.top = cr.top + n;
	}
	else{
		int m = (cr.right-(cr.bottom - cr.top))/2;
		cr.right = cr.right - m;
		cr.left = cr.left + m;
	}
	this->Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
