
// UsingView.cpp : CUsingView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Using.h"
#endif

#include "UsingDoc.h"
#include "UsingView.h"
#include"w32.h"
#include "Dll.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CUsingView

IMPLEMENT_DYNCREATE(CUsingView, CView)

BEGIN_MESSAGE_MAP(CUsingView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CUsingView ����/����

CUsingView::CUsingView()
{
	// TODO: �ڴ˴���ӹ������

}

CUsingView::~CUsingView()
{
}

BOOL CUsingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CUsingView ����

void CUsingView::OnDraw(CDC* pDC)
{
	CUsingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CString s;
	int sum;
	sum = factorial(5);
	s.Format(_T("%d"), sum);
	pDC->TextOutW(100, 100, s);

	float d;
	CString s1;
	FAC t=FAC();
	d = t.convert(30.0);
	s1.Format(_T("%f"), d);
	pDC->TextOutW(200, 200, s1);

	CString s2;
	int sum1;
	sum1 = factorial_1(5);
	s2.Format(_T("%d"), sum1);
	pDC->TextOutW(300, 300, s2);

	float d1;
	CString s3;
	FACD R=FACD();
	d1 = R.convert(30.0);
	s3.Format(_T("%f"), d1);
	pDC->TextOutW(400, 400, s3);
}

void CUsingView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CUsingView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CUsingView ���

#ifdef _DEBUG
void CUsingView::AssertValid() const
{
	CView::AssertValid();
}

void CUsingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUsingDoc* CUsingView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUsingDoc)));
	return (CUsingDoc*)m_pDocument;
}
#endif //_DEBUG


// CUsingView ��Ϣ�������
