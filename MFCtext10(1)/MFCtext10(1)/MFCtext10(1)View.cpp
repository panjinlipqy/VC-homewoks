
// MFCtext10(1)View.cpp : CMFCtext101View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCtext10(1).h"
#endif

#include "MFCtext10(1)Doc.h"
#include "MFCtext10(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext101View

IMPLEMENT_DYNCREATE(CMFCtext101View, CView)

BEGIN_MESSAGE_MAP(CMFCtext101View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CMFCtext101View ����/����

CMFCtext101View::CMFCtext101View()
{
	// TODO: �ڴ˴���ӹ������
	r.top = 10;
	r.left = 10;
	r.bottom = 100;
	r.right = 1010;
   p.x = r.left + 5;
	p.y = r.top + 5;
}

CMFCtext101View::~CMFCtext101View()
{
}

BOOL CMFCtext101View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCtext101View ����

void CMFCtext101View::OnDraw(CDC* pDC)
{
	CMFCtext101Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(r);

	
}

void CMFCtext101View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext101View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext101View ���

#ifdef _DEBUG
void CMFCtext101View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext101View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext101Doc* CMFCtext101View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext101Doc)));
	return (CMFCtext101Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext101View ��Ϣ�������


void CMFCtext101View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	CClientDC dc(this);
	if(p.x >= r.right -5){
		p.x = r.left + 5;
		p.y = p.y+25;
	}else if(p.y + 25 >= r.bottom -5){
		dc.TextOutW(p.x+100,p.y,_T("������������������δ���ƣ�����������ſɼ�������"));
	}else{
		dc.TextOutW(p.x, p.y, (LPCTSTR)&nChar);
		CSize textsize;
		textsize = dc.GetTextExtent((LPCTSTR)&nChar);
		p.x = p.x+textsize.cx;
	}
	//Invalidate();
	CView::OnChar(nChar, nRepCnt, nFlags);
}
