
// MFCtext11(4)View.cpp : CMFCtext114View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCtext11(4).h"
#endif

#include "MFCtext11(4)Doc.h"
#include "MFCtext11(4)View.h"
#include "MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext114View

IMPLEMENT_DYNCREATE(CMFCtext114View, CView)

BEGIN_MESSAGE_MAP(CMFCtext114View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_POP, &CMFCtext114View::OnPop)
END_MESSAGE_MAP()

// CMFCtext114View ����/����

CMFCtext114View::CMFCtext114View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCtext114View::~CMFCtext114View()
{
}

BOOL CMFCtext114View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCtext114View ����

void CMFCtext114View::OnDraw(CDC* /*pDC*/)
{
	CMFCtext114Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CMFCtext114View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext114View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext114View ���

#ifdef _DEBUG
void CMFCtext114View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext114View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext114Doc* CMFCtext114View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext114Doc)));
	return (CMFCtext114Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext114View ��Ϣ�������





void CMFCtext114View::OnPop()
{
	// TODO: �ڴ���������������

	MyDlg dlg;
	t = dlg.DoModal();

	if(t == IDOK){
		a = dlg.x1;
		b = dlg.x2;
		c = dlg.x3;
	}
	
}
