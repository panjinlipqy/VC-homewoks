
// MFCtext14ʵ��2View.cpp : CMFCtext14ʵ��2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCtext14ʵ��2.h"
#endif

#include "MFCtext14ʵ��2Doc.h"
#include "MFCtext14ʵ��2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext14ʵ��2View

IMPLEMENT_DYNCREATE(CMFCtext14ʵ��2View, CView)

BEGIN_MESSAGE_MAP(CMFCtext14ʵ��2View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFCtext14ʵ��2View ����/����

CMFCtext14ʵ��2View::CMFCtext14ʵ��2View()
{
	// TODO: �ڴ˴���ӹ������
	flag = 0;

}

CMFCtext14ʵ��2View::~CMFCtext14ʵ��2View()
{
}

BOOL CMFCtext14ʵ��2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCtext14ʵ��2View ����

void CMFCtext14ʵ��2View::OnDraw(CDC* pDC)
{
	CMFCtext14ʵ��2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if(set)
	{
		
			SetTimer(0, rand()%400+100, NULL);
		     set = false;
	}

	for(int i = 0; i < pDoc->ca.GetSize(); i++)
	   pDC->Ellipse(pDoc->ca.GetAt(i));
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CMFCtext14ʵ��2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext14ʵ��2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext14ʵ��2View ���

#ifdef _DEBUG
void CMFCtext14ʵ��2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext14ʵ��2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext14ʵ��2Doc* CMFCtext14ʵ��2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext14ʵ��2Doc)));
	return (CMFCtext14ʵ��2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext14ʵ��2View ��Ϣ�������


void CMFCtext14ʵ��2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	flag = 1;
	if(flag==1)
	ps = point;
	CView::OnLButtonDown(nFlags, point);
}


void CMFCtext14ʵ��2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(flag==1)
	pe = point;
	flag = 0;
	
	
	CView::OnLButtonUp(nFlags, point);
}


void CMFCtext14ʵ��2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(flag == 1)
	pe = point;
	CView::OnMouseMove(nFlags, point);
}


void CMFCtext14ʵ��2View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	re.left = ps.x;
	re.top = ps.y;
	re.bottom = pe.y;
	re.right = pe.x;
	CMFCtext14ʵ��2Doc* pDoc = GetDocument();
	CClientDC dc(this);
	if(flag ==0)
	pDoc->ca.Add(re);
	//else dc.Ellipse(re);
	Invalidate();
	CView::OnTimer(nIDEvent);
}
