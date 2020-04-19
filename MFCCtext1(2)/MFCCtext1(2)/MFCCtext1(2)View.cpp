
// MFCCtext1(2)View.cpp : CMFCCtext12View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCCtext1(2).h"
#endif

#include "MFCCtext1(2)Doc.h"
#include "MFCCtext1(2)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCCtext12View

IMPLEMENT_DYNCREATE(CMFCCtext12View, CView)

BEGIN_MESSAGE_MAP(CMFCCtext12View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCCtext12View ����/����

CMFCCtext12View::CMFCCtext12View()
{
	// TODO: �ڴ˴���ӹ������
	r.bottom = 0;
	r.top = 0;
	r.left = 0;
	r.right = 0;
}

CMFCCtext12View::~CMFCCtext12View()
{
}

BOOL CMFCCtext12View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCCtext12View ����

void CMFCCtext12View::OnDraw(CDC* pDC)
{
	CMFCCtext12Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Ellipse(r);
	
}

void CMFCCtext12View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCCtext12View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCCtext12View ���

#ifdef _DEBUG
void CMFCCtext12View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCCtext12View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCCtext12Doc* CMFCCtext12View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCCtext12Doc)));
	return (CMFCCtext12Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCCtext12View ��Ϣ�������


void CMFCCtext12View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int a = rand()%70+4;
	//CClientDC dc(this);
	
	r.bottom = point.y + a;
	r.top = point.y - a;
	r.left = point.x - a;
	r.right = point.x + a;
	//dc.Ellipse(r);
	Invalidate();
	
	CView::OnLButtonDown(nFlags, point);
}
