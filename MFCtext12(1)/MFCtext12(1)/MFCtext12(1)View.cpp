
// MFCtext12(1)View.cpp : CMFCtext121View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCtext12(1).h"
#endif

#include "MFCtext12(1)Doc.h"
#include "MFCtext12(1)View.h"
#include "Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext121View

IMPLEMENT_DYNCREATE(CMFCtext121View, CView)

BEGIN_MESSAGE_MAP(CMFCtext121View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_FILE_OPEN, &CMFCtext121View::OnFileOpen)
	ON_COMMAND(ID_POP, &CMFCtext121View::OnPop)
END_MESSAGE_MAP()

// CMFCtext121View ����/����

CMFCtext121View::CMFCtext121View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFCtext121View::~CMFCtext121View()
{
}

BOOL CMFCtext121View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCtext121View ����

void CMFCtext121View::OnDraw(CDC* pDC)
{
	CMFCtext121Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CMFCtext121View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext121View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext121View ���

#ifdef _DEBUG
void CMFCtext121View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext121View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext121Doc* CMFCtext121View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext121Doc)));
	return (CMFCtext121Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext121View ��Ϣ�������


void CMFCtext121View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	CFileDialog dlg(true);
	int r = dlg.DoModal(); //ģʽ�Ի���,�ѵ���
	if(r == IDOK){
		CClientDC dc(this);
		 s1 = dlg.GetFileName();
		GetDC()->TextOutW(100, 100, s1);
	}
	CView::OnLButtonDblClk(nFlags, point);
}


void CMFCtext121View::OnFileOpen()
{
	// TODO: �ڴ���������������
	
}


void CMFCtext121View::OnPop()
{
	// TODO: �ڴ���������������
	
	Dlg dlg;
	int t = dlg.DoModal();
	CClientDC dc(this);
	CString s;
	s = s1;
	//GetDC()->TextOutW(500, 100, dlg.name);
	if(t = IDOK){
		//s1 = dlg.name;
		pD->UpdateData(true);
		dlg.name= s1;
		//s1 = dlg.s;
		UpdateData(false);
	}
	
}
