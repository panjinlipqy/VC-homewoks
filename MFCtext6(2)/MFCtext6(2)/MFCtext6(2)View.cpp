
// MFCtext6(2)View.cpp : CMFCtext62View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCtext6(2).h"
#endif

#include "MFCtext6(2)Doc.h"
#include "MFCtext6(2)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext62View

IMPLEMENT_DYNCREATE(CMFCtext62View, CView)

BEGIN_MESSAGE_MAP(CMFCtext62View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CMFCtext62View ����/����

CMFCtext62View::CMFCtext62View()
{
	// TODO: �ڴ˴���ӹ������
	r.left = 100;
	r.right = 400;
	r.top = 100;
	r.bottom = 300;
}

CMFCtext62View::~CMFCtext62View()
{
}

BOOL CMFCtext62View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCtext62View ����

void CMFCtext62View::OnDraw(CDC* pDC)
{
	CMFCtext62Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(r);
}

void CMFCtext62View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext62View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext62View ���

#ifdef _DEBUG
void CMFCtext62View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext62View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext62Doc* CMFCtext62View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext62Doc)));
	return (CMFCtext62Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext62View ��Ϣ�������


void CMFCtext62View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	GetClientRect(&R);
	switch(nChar)
	{
	  case VK_LEFT:
		if(r.left > 0)
		{
			r.left -= 10;
			r.right -= 10;
		}
		break;
		case VK_RIGHT:
			if(r.right < R.right)
		{
			r.left += 10;
			r.right += 10;
		}
			break;
		case VK_UP:
			if(r.top > 0)
			{
				r.top -= 10;
				r.bottom -= 10;
			}
			break;
		case VK_DOWN:
			if(r.bottom < R.bottom)
			{
				r.bottom += 10;
				r.top += 10;
			}
			break;
		case VK_HOME:
			if(r.right < R.right && r.top > 0)
			{
				r.right += 10;
				r.top -= 10;
			}
			break;
		case VK_END:
			if(r.bottom < R.bottom && r.left > 0)
			{
				r.bottom += 10;
				r.left  -= 10;
			}
	
	}
	Invalidate();

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
