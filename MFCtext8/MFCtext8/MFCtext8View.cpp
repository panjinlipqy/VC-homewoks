
// MFCtext8View.cpp : CMFCtext8View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCtext8.h"
#endif

#include "MFCtext8Doc.h"
#include "MFCtext8View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext8View

IMPLEMENT_DYNCREATE(CMFCtext8View, CView)

BEGIN_MESSAGE_MAP(CMFCtext8View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_SHOW, &CMFCtext8View::OnShow)
END_MESSAGE_MAP()

// CMFCtext8View ����/����

CMFCtext8View::CMFCtext8View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCtext8View::~CMFCtext8View()
{
}

BOOL CMFCtext8View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCtext8View ����

void CMFCtext8View::OnDraw(CDC* /*pDC*/)
{
	CMFCtext8Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CMFCtext8View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext8View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext8View ���

#ifdef _DEBUG
void CMFCtext8View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext8View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext8Doc* CMFCtext8View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext8Doc)));
	return (CMFCtext8Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext8View ��Ϣ�������


void CMFCtext8View::OnShow()
{
	// TODO: �ڴ���������������
	CString s = _T("��ץ��������"); 
	CClientDC dc(this);
	dc.TextOutW(200, 300, s);
}
