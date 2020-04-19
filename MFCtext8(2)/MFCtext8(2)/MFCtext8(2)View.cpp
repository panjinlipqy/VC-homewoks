
// MFCtext8(2)View.cpp : CMFCtext82View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCtext8(2).h"
#endif

#include "MFCtext8(2)Doc.h"
#include "MFCtext8(2)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext82View

IMPLEMENT_DYNCREATE(CMFCtext82View, CView)

BEGIN_MESSAGE_MAP(CMFCtext82View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_SHOW_IMG, &CMFCtext82View::OnShowImg)
END_MESSAGE_MAP()

// CMFCtext82View ����/����

CMFCtext82View::CMFCtext82View()
{
	// TODO: �ڴ˴���ӹ������
	BITMAP BM;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&BM);
	m_nWidth = BM.bmWidth;
	m_nHeight = BM.bmHeight;
}

CMFCtext82View::~CMFCtext82View()
{
}

BOOL CMFCtext82View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCtext82View ����

void CMFCtext82View::OnDraw(CDC* pDC)
{
	CMFCtext82Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	
}

void CMFCtext82View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext82View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext82View ���

#ifdef _DEBUG
void CMFCtext82View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext82View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext82Doc* CMFCtext82View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext82Doc)));
	return (CMFCtext82Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext82View ��Ϣ�������


void CMFCtext82View::OnShowImg()
{
	// TODO: �ڴ���������������
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);
	CClientDC dc(this);
	dc.BitBlt(0, 0, m_nWidth, m_nHeight, &MemDC, 0, 0, SRCCOPY);
	
}
