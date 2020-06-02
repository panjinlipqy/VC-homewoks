// MyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCtext14实验1.h"
#include "MyDlg.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include <iostream>
#include<string>
#include<fstream>
using namespace std;


// MyDlg 对话框

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


// MyDlg 消息处理程序


BOOL MyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
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
	// 异常: OCX 属性页应返回 FALSE
}


void MyDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	int n = Lbox.GetCurSel();
	Lbox.GetText(n, s);
	UpdateData(true);
	cs = s;
	UpdateData(false);
}


void MyDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码

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
