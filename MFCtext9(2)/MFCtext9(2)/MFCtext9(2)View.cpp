
// MFCtext9(2)View.cpp : CMFCtext92View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCtext9(2).h"
#endif

#include "MFCtext9(2)Doc.h"
#include "MFCtext9(2)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext92View

IMPLEMENT_DYNCREATE(CMFCtext92View, CView)

BEGIN_MESSAGE_MAP(CMFCtext92View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_FILE_OPEN, &CMFCtext92View::OnFileOpen)
END_MESSAGE_MAP()

// CMFCtext92View ����/����

CMFCtext92View::CMFCtext92View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCtext92View::~CMFCtext92View()
{
}

BOOL CMFCtext92View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCtext92View ����

void CMFCtext92View::OnDraw(CDC* /*pDC*/)
{
	CMFCtext92Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CMFCtext92View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext92View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext92View ���

#ifdef _DEBUG
void CMFCtext92View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext92View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext92Doc* CMFCtext92View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext92Doc)));
	return (CMFCtext92Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext92View ��Ϣ�������


void CMFCtext92View::OnFileOpen()
{
	// TODO: �ڴ���������������
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	CClientDC dc(this);
	CString filename = cfd.GetPathName();
	CImage img;    
	img.Load(filename);
	if (r == IDOK){
		int w, h, sx, sy; //w,h��ߣ�sx,sy,ͼƬλ�ã����Ͻ��Ǹ���
		CRect rect;
		GetClientRect(&rect);  //��ȡ��ǰ�ͻ�����С

		float rect_ratio = 1.0*rect.Width() / rect.Height();
		float img_ratio = 1.0*img.GetWidth() / img.GetHeight();  //��ȡ�ͻ�����ͼƬ�Ŀ�߱�

		if(rect_ratio > img_ratio)
		{
			h = rect.Height();
			w = img_ratio*h;
			sx = (rect.Width() - w) /2;
			sy = 0;
		}
		else{
			w = rect.Width();
			h = w / img_ratio;
			sx = 0;
			sy = (rect.Height() - h)/2;
		}
		img.Draw(dc.m_hDC, sx, sy, w, h);
		dc.TextOutW(0, 0, filename);
	}
}
