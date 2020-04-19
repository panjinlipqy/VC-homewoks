
// MFCtext3(2)View.cpp : CMFCtext32View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCtext3(2).h"
#endif

#include "MFCtext3(2)Doc.h"
#include "MFCtext3(2)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext32View

IMPLEMENT_DYNCREATE(CMFCtext32View, CView)

BEGIN_MESSAGE_MAP(CMFCtext32View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCtext32View ����/����

CMFCtext32View::CMFCtext32View()
{
	// TODO: �ڴ˴���ӹ������
}

CMFCtext32View::~CMFCtext32View()
{
}

BOOL CMFCtext32View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCtext32View ����

void CMFCtext32View::OnDraw(CDC* pDC)
{
	CMFCtext32Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	for(int i = 0; i < pDoc->ca.GetSize(); i++)
	   pDC->Ellipse(pDoc->ca.GetAt(i));
}

void CMFCtext32View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext32View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext32View ���

#ifdef _DEBUG
void CMFCtext32View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext32View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext32Doc* CMFCtext32View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext32Doc)));
	return (CMFCtext32Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext32View ��Ϣ�������


void CMFCtext32View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	r = rand() % 50 + 5;
	r2 = rand()%50+3;
	CRect cr(point.x-r, point.y-r2, point.x+r, point.y+r2);
	
	CMFCtext32Doc* pDoc = GetDocument();
	pDoc->ca.Add(cr);
	this->Invalidate();

	//CClientDC dc(this);
	//dc.Ellipse(cr);
	CView::OnLButtonDown(nFlags, point);
}
