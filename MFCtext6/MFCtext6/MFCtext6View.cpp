
// MFCtext6View.cpp : CMFCtext6View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCtext6.h"
#endif

#include "MFCtext6Doc.h"
#include "MFCtext6View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext6View

IMPLEMENT_DYNCREATE(CMFCtext6View, CView)

BEGIN_MESSAGE_MAP(CMFCtext6View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCtext6View ����/����

CMFCtext6View::CMFCtext6View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCtext6View::~CMFCtext6View()
{
}

BOOL CMFCtext6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCtext6View ����

void CMFCtext6View::OnDraw(CDC* /*pDC*/)
{
	CMFCtext6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CMFCtext6View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext6View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext6View ���

#ifdef _DEBUG
void CMFCtext6View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext6View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext6Doc* CMFCtext6View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext6Doc)));
	return (CMFCtext6Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext6View ��Ϣ�������
