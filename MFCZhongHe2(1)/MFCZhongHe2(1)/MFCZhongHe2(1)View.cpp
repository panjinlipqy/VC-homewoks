
// MFCZhongHe2(1)View.cpp : CMFCZhongHe21View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCZhongHe2(1).h"
#endif

#include "MFCZhongHe2(1)Set.h"
#include "MFCZhongHe2(1)Doc.h"
#include "MFCZhongHe2(1)View.h"
#include "Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCZhongHe21View

IMPLEMENT_DYNCREATE(CMFCZhongHe21View, CRecordView)

BEGIN_MESSAGE_MAP(CMFCZhongHe21View, CRecordView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_EN_CHANGE(IDC_EDIT2, &CMFCZhongHe21View::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCZhongHe21View::OnBnClickedButton1)
	ON_COMMAND(ID_RECORD_FIRST, &CMFCZhongHe21View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMFCZhongHe21View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFCZhongHe21View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMFCZhongHe21View::OnRecordLast)
END_MESSAGE_MAP()

// CMFCZhongHe21View ����/����

CMFCZhongHe21View::CMFCZhongHe21View()
	: CRecordView(CMFCZhongHe21View::IDD)
	, name(_T(""))
	, id(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CMFCZhongHe21View::~CMFCZhongHe21View()
{
}

void CMFCZhongHe21View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column2);
}

BOOL CMFCZhongHe21View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFCZhongHe21View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCZhongHe21Set;
	CRecordView::OnInitialUpdate();

}

void CMFCZhongHe21View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCZhongHe21View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCZhongHe21View ���

#ifdef _DEBUG
void CMFCZhongHe21View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCZhongHe21View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCZhongHe21Doc* CMFCZhongHe21View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCZhongHe21Doc)));
	return (CMFCZhongHe21Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCZhongHe21View ���ݿ�֧��
CRecordset* CMFCZhongHe21View::OnGetRecordset()
{
	return m_pSet;
}



// CMFCZhongHe21View ��Ϣ�������


void CMFCZhongHe21View::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CRecordView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CMFCZhongHe21View::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	/*Dlg dlg;
	int t = dlg.DoModal();
	if(t = IDOK){
	//UpdateData(false);
	CString filename;
	filename = m_pSet->column3;
	draw1(filename);
	}*/

	Dlg *pd = new Dlg;
	pd->Create(IDD_DIALOG1);
	pd->ShowWindow(1);
	CString file;
	file = m_pSet->column3;
	
	CImage img;
	img.Load(file);
	CDC* pDC = pd->GetDlgItem(IDC_STATIC)->GetDC();
	int sx, sy, w, h;
	CRect rect;
	pd->GetDlgItem(IDC_STATIC)->GetClientRect(&rect);

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
		img.Draw(pDC->m_hDC, sx, sy, w, h);
}


void CMFCZhongHe21View::draw(CString file)
{
	CImage img;
	img.Load(file);
	CDC* pDC = GetDlgItem(IDC_STATIC)->GetDC();
	int sx, sy, w, h;
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);

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
		img.Draw(pDC->m_hDC, sx, sy, w, h);

}


	

void CMFCZhongHe21View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
	CString filename;
	filename = m_pSet->column3;
	draw(filename);
}


void CMFCZhongHe21View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if(m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	CString filename;
	filename = m_pSet->column3;
	draw(filename);
}


void CMFCZhongHe21View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if(m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	CString filename;
	filename = m_pSet->column3;
	draw(filename);
}


void CMFCZhongHe21View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);
	CString filename;
	filename = m_pSet->column3;
	draw(filename);
}
