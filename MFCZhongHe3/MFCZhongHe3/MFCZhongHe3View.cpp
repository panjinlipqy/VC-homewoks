
// MFCZhongHe3View.cpp : CMFCZhongHe3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCZhongHe3.h"
#endif

#include "MFCZhongHe3Set.h"
#include "MFCZhongHe3Doc.h"
#include "MFCZhongHe3View.h"
#include "ADDdlg.h"
#include "changeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCZhongHe3View

IMPLEMENT_DYNCREATE(CMFCZhongHe3View, CRecordView)

BEGIN_MESSAGE_MAP(CMFCZhongHe3View, CRecordView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCZhongHe3View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCZhongHe3View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCZhongHe3View::OnBnClickedButton3)
END_MESSAGE_MAP()

// CMFCZhongHe3View ����/����

CMFCZhongHe3View::CMFCZhongHe3View()
	: CRecordView(CMFCZhongHe3View::IDD)
	, text(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CMFCZhongHe3View::~CMFCZhongHe3View()
{
}

void CMFCZhongHe3View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL CMFCZhongHe3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFCZhongHe3View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCZhongHe3Set;
	CRecordView::OnInitialUpdate();

}

void CMFCZhongHe3View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCZhongHe3View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCZhongHe3View ���

#ifdef _DEBUG
void CMFCZhongHe3View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCZhongHe3View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCZhongHe3Doc* CMFCZhongHe3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCZhongHe3Doc)));
	return (CMFCZhongHe3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCZhongHe3View ���ݿ�֧��
CRecordset* CMFCZhongHe3View::OnGetRecordset()
{
	return m_pSet;
}



// CMFCZhongHe3View ��Ϣ�������


void CMFCZhongHe3View::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ADDdlg add;
	int r= add.DoModal();
	if(r==IDOK)
	{
		long ii = add.i;
		m_pSet->AddNew();
		m_pSet->m_1=ii;
		m_pSet->Update();
		UpdateData(false);
	}
	
}


void CMFCZhongHe3View::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	changeDlg change;
	int r= change.DoModal();
	if(r==IDOK){
		long tt = change.t;
		m_pSet->Edit();
		m_pSet->m_1=tt;
		m_pSet->Update();
		UpdateData(false);
	}
}


void CMFCZhongHe3View::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_pSet->Delete();
	m_pSet->MovePrev();
	if(m_pSet->IsBOF()) 
		m_pSet->MoveFirst();
	UpdateData(false);
}
