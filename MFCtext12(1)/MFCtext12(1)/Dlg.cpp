// Dlg.cpp : ʵ���ļ�
//
#include "MFCtext12(1)Doc.h"
#include "MFCtext12(1)View.h"
#include "stdafx.h"
#include "MFCtext12(1).h"
#include "Dlg.h"
#include "afxdialogex.h"


// Dlg �Ի���

IMPLEMENT_DYNAMIC(Dlg, CDialogEx)

Dlg::Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Dlg::IDD, pParent)
	, name(_T(""))
{
	
}

Dlg::~Dlg()
{
	s="";
}

void Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, name);
}


BEGIN_MESSAGE_MAP(Dlg, CDialogEx)
	ON_WM_LBUTTONDBLCLK()
	ON_EN_CHANGE(IDC_EDIT1, &Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON2, &Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// Dlg ��Ϣ�������





void Dlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void Dlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//this->UpdateData(true);
	//name = name + name + _T("1");
	//UpdateData(false);
}


BOOL Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CMFCtext121Doc* pDoc = ((CMFCtext121View*)((CFrameWnd*)AfxGetMainWnd())->GetActiveView())->GetDocument();
	SetDlgtemText(IDC_EDIT1, pDoc->s1);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
