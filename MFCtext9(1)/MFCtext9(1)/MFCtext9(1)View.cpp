
// MFCtext9(1)View.cpp : CMFCtext91View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCtext9(1).h"
#endif

#include "MFCtext9(1)Doc.h"
#include "MFCtext9(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext91View

IMPLEMENT_DYNCREATE(CMFCtext91View, CView)

BEGIN_MESSAGE_MAP(CMFCtext91View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_FILE_OPEN, &CMFCtext91View::OnFileOpen)
END_MESSAGE_MAP()

// CMFCtext91View ����/����

CMFCtext91View::CMFCtext91View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCtext91View::~CMFCtext91View()
{
}

BOOL CMFCtext91View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCtext91View ����

void CMFCtext91View::OnDraw(CDC* /*pDC*/)
{
	CMFCtext91Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CMFCtext91View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext91View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext91View ���

#ifdef _DEBUG
void CMFCtext91View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext91View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext91Doc* CMFCtext91View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext91Doc)));
	return (CMFCtext91Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext91View ��Ϣ�������


void CMFCtext91View::OnFileOpen()
{
	// TODO: �ڴ���������������
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	CClientDC dc(this);
	CString filename = cfd.GetPathName();
	CImage img;    
		img.Load(filename);
		int sx, sy; //w,h��ߣ�sx,sy,ͼƬλ�ã����Ͻ��Ǹ���
		CRect rect;
		GetClientRect(&rect);  //��ȡ��ǰ�ͻ�����С

		sx = (rect.Width() - img.GetWidth()) / 2;
		sy = (rect.Height() - img.GetHeight()) /2;
		img.Draw(dc.m_hDC, sx, sy, img.GetWidth(), img.GetHeight());

	if (r == IDOK)
		dc.TextOutW(0, 0, filename); //�ڶԻ�������򿪵��ļ���
		

	
}
