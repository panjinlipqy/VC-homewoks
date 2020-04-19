
// MFCtext1(4)View.cpp : CMFCtext14View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCtext1(4).h"
#endif

#include "MFCtext1(4)Doc.h"
#include "MFCtext1(4)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext14View

IMPLEMENT_DYNCREATE(CMFCtext14View, CView)

BEGIN_MESSAGE_MAP(CMFCtext14View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCtext14View ����/����

CMFCtext14View::CMFCtext14View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCtext14View::~CMFCtext14View()
{
}

BOOL CMFCtext14View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCtext14View ����

void CMFCtext14View::OnDraw(CDC* pDC)
{
	CMFCtext14Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	GetClientRect(&cr);
	CBrush m_brush;
	m_brush.CreateSolidBrush(RGB(20,50,50));
	CBrush *oldbrush;
    oldbrush = pDC->SelectObject(&m_brush);
	pDC->Ellipse(cr);
	pDC->SelectObject(oldbrush);
}

void CMFCtext14View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext14View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext14View ���

#ifdef _DEBUG
void CMFCtext14View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext14View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext14Doc* CMFCtext14View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext14Doc)));
	return (CMFCtext14Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext14View ��Ϣ�������
