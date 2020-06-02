// MyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCtext14ʵ��1.h"
#include "MyDlg.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include <iostream>
#include<string>
#include<fstream>
using namespace std;


// MyDlg �Ի���

IMPLEMENT_DYNAMIC(MyDlg, CDialogEx)

MyDlg::MyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(MyDlg::IDD, pParent)
	, cs(_T(""))
{

}

MyDlg::~MyDlg()
{
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, Lbox);
	DDX_Text(pDX, IDC_EDIT1, cs);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MyDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDOK, &MyDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// MyDlg ��Ϣ�������


BOOL MyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CFileDialog cdf(true);
	int r = cdf.DoModal();
	if(r==IDOK)
	{
		filename = cdf.GetPathName();
		ifstream ifs(filename);
		string s;

		CClientDC dc(this);
		while(getline(ifs, s))
		{
			CString d;
			d = CString(s.c_str());
			Lbox.AddString(d);
		}
	}

	s="";

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void MyDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int n = Lbox.GetCurSel();
	Lbox.GetText(n, s);
	UpdateData(true);
	cs = s;
	UpdateData(false);
}


void MyDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int n = Lbox.GetCurSel();
	UpdateData(true);
	Lbox.DeleteString(n);
	CString s1;
	s1 = cs;
	Lbox.AddString(s1);
	UpdateData(false);
}

string CString2string(CString csStrData){	
	string strRet ; 	
	char ss[2048];	
	memset(ss, 0, sizeof(char)*2048);	
	sprintf(ss, "%s", csStrData); 	
	strRet = ss;	
	return strRet;
}


void MyDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	ofstream ofs(filename);
	int sum = Lbox.GetCount();
	string q;
	CString t;
	
	for(int i=0; i<sum;i++){
	   Lbox.GetText(i,t);
		q = CT2A(t.GetString());
		ofs<<q <<endl;
	}
	
	CDialogEx::OnOK();
}
