
// MFCtext(2)View.cpp : CMFCtext2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCtext(2).h"
#endif

#include "MFCtext(2)Doc.h"
#include "MFCtext(2)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext2View

IMPLEMENT_DYNCREATE(CMFCtext2View, CView)

BEGIN_MESSAGE_MAP(CMFCtext2View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
	ON_WM_SETFOCUS()
END_MESSAGE_MAP()

// CMFCtext2View ����/����

CMFCtext2View::CMFCtext2View()
{
	// TODO: �ڴ˴���ӹ������
	r.top = 10;
	r.left = 10;
	r.bottom = 100;
	r.right = 1010;
   p.x = r.left + 5;
	p.y = r.top + 5;
	flag = false;
}

CMFCtext2View::~CMFCtext2View()
{
}

BOOL CMFCtext2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCtext2View ����

void CMFCtext2View::OnDraw(CDC* pDC)
{
	CMFCtext2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(r);
}

void CMFCtext2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext2View ���

#ifdef _DEBUG
void CMFCtext2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext2Doc* CMFCtext2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext2Doc)));
	return (CMFCtext2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext2View ��Ϣ�������


void CMFCtext2View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	
	if(p.x >= r.right -5){
		p.x = r.left + 5;
		p.y = p.y+25;
		 SetCaretPos(p);
         ShowCaret();
	}else if(p.y + 25 >= r.bottom -5 ){
		dc.TextOutW(p.x+100,p.y,_T("������������������δ���ƣ�����������ſɼ�������"));
	}else if(flag == false){
		HideCaret();
		dc.TextOutW(p.x, p.y, (LPCTSTR)&nChar);
		CSize textsize;
		textsize = dc.GetTextExtent((LPCTSTR)&nChar);
		p.x = p.x+textsize.cx;
		  SetCaretPos(p);
         ShowCaret();
	}
	//Invalidate();
	if(flag == true){
		HideCaret();
		dc.TextOutW(ps.x, ps.y, (LPCTSTR)&nChar);
		CSize textsize;
		textsize = dc.GetTextExtent((LPCTSTR)&nChar);
		p.x = p.x+textsize.cx;
		ps.x = ps.x + textsize.cx;
		  SetCaretPos(ps);
         ShowCaret();
	}
	
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMFCtext2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	ps.x = point.x;
	ps.y = p.y;
	 SetCaretPos(ps);
         ShowCaret();
		 flag = true;
	CView::OnLButtonDown(nFlags, point);
}


void CMFCtext2View::OnSetFocus(CWnd* pOldWnd)
{
	CView::OnSetFocus(pOldWnd);

	// TODO: �ڴ˴������Ϣ����������
	CreateSolidCaret(3, 18);
    SetCaretPos(p);
     ShowCaret();
}
