
// MFCtext13(2)(1)View.cpp : CMFCtext1321View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCtext13(2)(1).h"
#endif

#include "MFCtext13(2)(1)Doc.h"
#include "MFCtext13(2)(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext1321View

IMPLEMENT_DYNCREATE(CMFCtext1321View, CView)

BEGIN_MESSAGE_MAP(CMFCtext1321View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_TIMER()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCtext1321View ����/����

CMFCtext1321View::CMFCtext1321View()
{
	// TODO: �ڴ˴���ӹ������
	re.bottom = 0;
	re.top = 0;
	re.left = 0;
	re.right = 0;
	rs.bottom = 0;
	rs.top = 0;
	rs.right = 0;
	rs.left = 0;
	flag = 0;
	pe.x= 0;
	pe.y=0;
	pt.x=0;
	pt.y = 0;
	ps.x= 0;
	ps.y =0;

}

CMFCtext1321View::~CMFCtext1321View()
{
}

BOOL CMFCtext1321View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCtext1321View ����

void CMFCtext1321View::OnDraw(CDC* pDC)
{
	CMFCtext1321Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if(set)
	{
		
			SetTimer(0, rand()%400+100, NULL);
		     set = false;
	}
	pDC->Ellipse(rs);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CMFCtext1321View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext1321View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext1321View ���

#ifdef _DEBUG
void CMFCtext1321View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext1321View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext1321Doc* CMFCtext1321View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext1321Doc)));
	return (CMFCtext1321Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext1321View ��Ϣ�������


void CMFCtext1321View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(flag == 0) {
    pe.x= 0;
	pe.y=0;
	pt.x=0;
	pt.y = 0;
	ps.x= 0;
	ps.y =0;

	}
	ps = point;
	flag = 1;
	//Invalidate();
	CView::OnLButtonDown(nFlags, point);
}


void CMFCtext1321View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	pe = pt;
	flag = 0;
	CView::OnLButtonUp(nFlags, point);
}


void CMFCtext1321View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	rs.left = ps.x;
	rs.top = ps.y;
	if(rs.right < pt.x && pe.x == 0) rs.right = pt.x;
	else if(pe.x != 0) rs.right = pe.x;

	if(rs.bottom < pt.y && pe.y == 0) rs.bottom = pt.y;
	else if (pe.y != 0) rs.bottom = pe.y;
	Invalidate();
	CView::OnTimer(nIDEvent);
}


void CMFCtext1321View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (flag == 1)
	pt = point;
	CView::OnMouseMove(nFlags, point);
}
