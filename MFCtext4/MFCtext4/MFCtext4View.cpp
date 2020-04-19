
// MFCtext4View.cpp : CMFCtext4View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCtext4.h"
#endif

#include "MFCtext4Doc.h"
#include "MFCtext4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext4View

IMPLEMENT_DYNCREATE(CMFCtext4View, CView)

BEGIN_MESSAGE_MAP(CMFCtext4View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFCtext4View ����/����

CMFCtext4View::CMFCtext4View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCtext4View::~CMFCtext4View()
{
}

BOOL CMFCtext4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCtext4View ����

void CMFCtext4View::OnDraw(CDC* /*pDC*/)
{
	CMFCtext4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CMFCtext4View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext4View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext4View ���

#ifdef _DEBUG
void CMFCtext4View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext4Doc* CMFCtext4View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext4Doc)));
	return (CMFCtext4Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext4View ��Ϣ�������


void CMFCtext4View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString d= _T("�����������");
	CClientDC dc(this);
	dc.TextOutW(200,200, d);

	CView::OnLButtonDown(nFlags, point);
}


void CMFCtext4View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString u= _T("�����̧��");
	CClientDC dc(this);
	dc.TextOutW(200,300, u);
	CView::OnLButtonUp(nFlags, point);
}
