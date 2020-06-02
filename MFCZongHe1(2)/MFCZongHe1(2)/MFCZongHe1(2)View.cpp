
// MFCZongHe1(2)View.cpp : CMFCZongHe12View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCZongHe1(2).h"
#endif

#include "MFCZongHe1(2)Set.h"
#include "MFCZongHe1(2)Doc.h"
#include "MFCZongHe1(2)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCZongHe12View

IMPLEMENT_DYNCREATE(CMFCZongHe12View, CRecordView)

BEGIN_MESSAGE_MAP(CMFCZongHe12View, CRecordView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_RECORD_FIRST, &CMFCZongHe12View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMFCZongHe12View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFCZongHe12View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMFCZongHe12View::OnRecordLast)
END_MESSAGE_MAP()

// CMFCZongHe12View ����/����

CMFCZongHe12View::CMFCZongHe12View()
	: CRecordView(CMFCZongHe12View::IDD)
	, name(_T(""))
	, id(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CMFCZongHe12View::~CMFCZongHe12View()
{
}

void CMFCZongHe12View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_2);
}

BOOL CMFCZongHe12View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFCZongHe12View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCZongHe12Set;
	CRecordView::OnInitialUpdate();

}

void CMFCZongHe12View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCZongHe12View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCZongHe12View ���

#ifdef _DEBUG
void CMFCZongHe12View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCZongHe12View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCZongHe12Doc* CMFCZongHe12View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCZongHe12Doc)));
	return (CMFCZongHe12Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCZongHe12View ���ݿ�֧��
CRecordset* CMFCZongHe12View::OnGetRecordset()
{
	return m_pSet;
}



// CMFCZongHe12View ��Ϣ�������
void CMFCZongHe12View::draw(CString file)
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

void CMFCZongHe12View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
	CString filename;
	filename = m_pSet->m_3;
	draw(filename);
}


void CMFCZongHe12View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if(m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	CString filename;
	filename = m_pSet->m_3;
	draw(filename);
}


void CMFCZongHe12View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if(m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	CString filename;
	filename = m_pSet->m_3;
	draw(filename);
}


void CMFCZongHe12View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);
	CString filename;
	filename = m_pSet->m_3;
	draw(filename);
}
