
// MFCtext1(3)View.cpp : CMFCtext13View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCtext1(3).h"
#endif

#include "MFCtext1(3)Doc.h"
#include "MFCtext1(3)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext13View

IMPLEMENT_DYNCREATE(CMFCtext13View, CView)

BEGIN_MESSAGE_MAP(CMFCtext13View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCtext13View ����/����

CMFCtext13View::CMFCtext13View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCtext13View::~CMFCtext13View()
{
}

BOOL CMFCtext13View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCtext13View ����

void CMFCtext13View::OnDraw(CDC* pDC)
{
	CMFCtext13Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	GetClientRect(&cr);
	pDC->Ellipse(cr);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CMFCtext13View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext13View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext13View ���

#ifdef _DEBUG
void CMFCtext13View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext13View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext13Doc* CMFCtext13View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext13Doc)));
	return (CMFCtext13Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext13View ��Ϣ�������
