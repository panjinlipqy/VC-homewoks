
// MFCtext11(2)View.cpp : CMFCtext112View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCtext11(2).h"
#endif

#include "MFCtext11(2)Doc.h"
#include "MFCtext11(2)View.h"
#include "Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext112View

IMPLEMENT_DYNCREATE(CMFCtext112View, CView)

BEGIN_MESSAGE_MAP(CMFCtext112View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_POP, &CMFCtext112View::OnPop)
END_MESSAGE_MAP()

// CMFCtext112View ����/����

CMFCtext112View::CMFCtext112View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCtext112View::~CMFCtext112View()
{
}

BOOL CMFCtext112View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCtext112View ����

void CMFCtext112View::OnDraw(CDC* /*pDC*/)
{
	CMFCtext112Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CMFCtext112View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext112View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext112View ���

#ifdef _DEBUG
void CMFCtext112View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext112View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext112Doc* CMFCtext112View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext112Doc)));
	return (CMFCtext112Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext112View ��Ϣ�������


void CMFCtext112View::OnPop()
{
	// TODO: �ڴ���������������
	Dlg dlg;
	int t = dlg.DoModal();

	if(t == IDOK){
		a = dlg.a;
		b = dlg.b;
		c = dlg.c;
	}
}


