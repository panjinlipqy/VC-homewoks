
// MFCtext14ʵ��1View.cpp : CMFCtext14ʵ��1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCtext14ʵ��1.h"
#endif

#include "MFCtext14ʵ��1Doc.h"
#include "MFCtext14ʵ��1View.h"
#include "MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext14ʵ��1View

IMPLEMENT_DYNCREATE(CMFCtext14ʵ��1View, CView)

BEGIN_MESSAGE_MAP(CMFCtext14ʵ��1View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	
END_MESSAGE_MAP()

// CMFCtext14ʵ��1View ����/����

CMFCtext14ʵ��1View::CMFCtext14ʵ��1View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCtext14ʵ��1View::~CMFCtext14ʵ��1View()
{
}

BOOL CMFCtext14ʵ��1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCtext14ʵ��1View ����

void CMFCtext14ʵ��1View::OnDraw(CDC* /*pDC*/)
{
	CMFCtext14ʵ��1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CMFCtext14ʵ��1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext14ʵ��1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext14ʵ��1View ���

#ifdef _DEBUG
void CMFCtext14ʵ��1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext14ʵ��1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext14ʵ��1Doc* CMFCtext14ʵ��1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext14ʵ��1Doc)));
	return (CMFCtext14ʵ��1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext14ʵ��1View ��Ϣ�������


void CMFCtext14ʵ��1View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	MyDlg md2;
	int r = md2.DoModal();
	if(r==IDOK)
	{
		//CString s1=md2.s;
		//GetDC()->TextOutW(100, 100, s1);
	}
	CView::OnLButtonDblClk(nFlags, point);
}



