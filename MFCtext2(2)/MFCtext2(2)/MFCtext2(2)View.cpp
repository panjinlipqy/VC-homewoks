
// MFCtext2(2)View.cpp : CMFCtext22View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCtext2(2).h"
#endif

#include "MFCtext2(2)Doc.h"
#include "MFCtext2(2)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext22View

IMPLEMENT_DYNCREATE(CMFCtext22View, CView)

BEGIN_MESSAGE_MAP(CMFCtext22View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCtext22View ����/����

CMFCtext22View::CMFCtext22View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCtext22View::~CMFCtext22View()
{
}

BOOL CMFCtext22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCtext22View ����

void CMFCtext22View::OnDraw(CDC* pDC)
{
	CMFCtext22Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

	pDC->TextOutW(100,100,pDoc->s);//(2)
	pDC->TextOutW(100,200,pDoc->s2);
}

void CMFCtext22View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext22View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext22View ���

#ifdef _DEBUG
void CMFCtext22View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext22View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext22Doc* CMFCtext22View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext22Doc)));
	return (CMFCtext22Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext22View ��Ϣ�������
