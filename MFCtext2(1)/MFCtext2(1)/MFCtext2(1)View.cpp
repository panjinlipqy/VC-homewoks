
// MFCtext2(1)View.cpp : CMFCtext21View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCtext2(1).h"
#endif

#include "MFCtext2(1)Doc.h"
#include "MFCtext2(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext21View

IMPLEMENT_DYNCREATE(CMFCtext21View, CView)

BEGIN_MESSAGE_MAP(CMFCtext21View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCtext21View ����/����

CMFCtext21View::CMFCtext21View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCtext21View::~CMFCtext21View()
{
}

BOOL CMFCtext21View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCtext21View ����

void CMFCtext21View::OnDraw(CDC* pDC)
{
	CMFCtext21Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CString s;   //(1)
	s = "������ץ��������pjl";
	int A = 8888;
	CString s2;
	s2.Format(_T("%d"), A);
	pDC->TextOutW(100,100,s);
	pDC->TextOutW(100,200,s2);
}

void CMFCtext21View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext21View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext21View ���

#ifdef _DEBUG
void CMFCtext21View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext21View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext21Doc* CMFCtext21View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext21Doc)));
	return (CMFCtext21Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext21View ��Ϣ�������
