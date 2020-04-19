
// MFCtext8(3)View.cpp : CMFCtext83View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCtext8(3).h"
#endif

#include "MFCtext8(3)Doc.h"
#include "MFCtext8(3)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext83View

IMPLEMENT_DYNCREATE(CMFCtext83View, CView)

BEGIN_MESSAGE_MAP(CMFCtext83View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_showline, &CMFCtext83View::Onshowline)
	ON_COMMAND(ID_showrect, &CMFCtext83View::Onshowrect)
	ON_COMMAND(ID_showelispse, &CMFCtext83View::Onshowelispse)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_TIMER()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFCtext83View ����/����

CMFCtext83View::CMFCtext83View()
{
	// TODO: �ڴ˴���ӹ������
	set = true;
	flag = 0;
}

CMFCtext83View::~CMFCtext83View()
{
}

BOOL CMFCtext83View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCtext83View ����

void CMFCtext83View::OnDraw(CDC* /*pDC*/)
{
	CMFCtext83Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

	
}

void CMFCtext83View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext83View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext83View ���

#ifdef _DEBUG
void CMFCtext83View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext83View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext83Doc* CMFCtext83View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext83Doc)));
	return (CMFCtext83Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext83View ��Ϣ�������


void CMFCtext83View::Onshowline()
{
	// TODO: �ڴ���������������
	
	
	flag = 1;
	//Invalidate();
}


void CMFCtext83View::Onshowrect()
{
	// TODO: �ڴ���������������
	
	
	flag = 2;
	
	//Invalidate();
}


void CMFCtext83View::Onshowelispse()
{
	// TODO: �ڴ���������������
	
	
	flag = 3;
	
	//Invalidate();
}


void CMFCtext83View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	sp.x = point.x;
	sp.y = point.y;

	CView::OnLButtonDown(nFlags, point);
}


void CMFCtext83View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	ep.x = point.x;
	ep.y = point.y;
	//Invalidate();
	r.bottom = ep.y;
	r.top = sp.y;
	r.left = sp.x;
	r.right = ep.x;
	switch(flag){
		case 3:
			dc.Ellipse(r);
			break;
		case 2:
			dc.Rectangle(r);
			break;
		case 1:
			dc.MoveTo(sp);	
	        dc.LineTo(ep);
			break;
	}

	CView::OnLButtonUp(nFlags, point);
}




