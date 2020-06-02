
// MFCtext14(1)View.cpp : CMFCtext141View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCtext14(1).h"
#endif

#include "MFCtext14(1)Doc.h"
#include "MFCtext14(1)View.h"

#include<fstream>
#include<string>
#include<iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCtext141View

IMPLEMENT_DYNCREATE(CMFCtext141View, CView)

BEGIN_MESSAGE_MAP(CMFCtext141View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_FILE_OPEN, &CMFCtext141View::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE_AS, &CMFCtext141View::OnFileSaveAs)
END_MESSAGE_MAP()

// CMFCtext141View ����/����

CMFCtext141View::CMFCtext141View()
{
	// TODO: �ڴ˴���ӹ������
	filename = _T(" ");

}

CMFCtext141View::~CMFCtext141View()
{
}

BOOL CMFCtext141View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCtext141View ����

void CMFCtext141View::OnDraw(CDC* pDC)
{
	CMFCtext141Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	
	
}

void CMFCtext141View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCtext141View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCtext141View ���

#ifdef _DEBUG
void CMFCtext141View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCtext141View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCtext141Doc* CMFCtext141View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCtext141Doc)));
	return (CMFCtext141Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCtext141View ��Ϣ�������


void CMFCtext141View::OnFileOpen()
{
	// TODO: �ڴ���������������
	CMFCtext141Doc* pDoc = GetDocument();

	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if(r == IDOK){
		filename = cfd.GetPathName();
		ifstream ifs(filename);//�����ļ���,�Ӵ����ļ����뵽Ӧ�ó���
		string s;

		CClientDC dc(this);
			//dc.TextOutW(300, 300, filename);

			int x = 20, y = 10;
			while(ifs >> s){
				dc.TextOutW(20, 10, CString(s.c_str()));
				y += 30;
			}
	}

}


void CMFCtext141View::OnFileSaveAs()
{
	// TODO: �ڴ���������������
	CFileDialog cfd(false);
	int r = cfd.DoModal();
	if(r == IDOK){
		ofstream ofs(cfd.GetPathName());
		//ofs << "OK" << endl;
		CString s = filename;
		ofs << CT2A(s.GetString()) << endl;
		//ofs << cfd.GetPathName() << endl;
	}
}
