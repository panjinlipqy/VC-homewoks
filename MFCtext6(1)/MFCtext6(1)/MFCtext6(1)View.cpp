
// MFCtext6(1)View.cpp : CMFCtext61View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCtext6(1).h"
#endif

#include "MFCtext6(1)Doc.h"
#include "MFCtext6(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext61View

IMPLEMENT_DYNCREATE(CMFCtext61View, CView)

BEGIN_MESSAGE_MAP(CMFCtext61View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFCtext61View ����/����

CMFCtext61View::CMFCtext61View()
{
	// TODO: �ڴ˴���ӹ������
	count = 0;
	s.Format(_T("%d"),count);

}

CMFCtext61View::~CMFCtext61View()
{

}

BOOL CMFCtext61View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCtext61View ����

void CMFCtext61View::OnDraw(CDC* /*pDC*/)
{
	CMFCtext61Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CMFCtext61View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext61View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext61View ���

#ifdef _DEBUG
void CMFCtext61View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext61View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext61Doc* CMFCtext61View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext61Doc)));
	return (CMFCtext61Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext61View ��Ϣ�������


void CMFCtext61View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	// count++;
	// s.Format(_T("%d"),count);
	// s1.Format(_T("%d"),p2.x-p1.x);
	// CClientDC dc(this);
	 //dc.TextOutW(point.x,point.y,s+s1);
	 count++;
	CView::OnMouseMove(nFlags, point);
}


void CMFCtext61View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	 p1 = point;
	 

	CView::OnLButtonDown(nFlags, point);
}


void CMFCtext61View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	p2 = point;
	//if(p1 != p2) count++;
	s.Format(_T("%d"),count);
	s1.Format(_T("%d"),p2.x-p1.x);
	 CClientDC dc(this);
	 dc.TextOutW(point.x,point.y, _T("MOUSEMOVE��������:") + s +"    "+"�����ƶ���������"+ s1);
	CView::OnLButtonUp(nFlags, point);
}
