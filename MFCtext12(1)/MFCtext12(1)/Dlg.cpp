// Dlg.cpp : 实现文件
//
#include "MFCtext12(1)Doc.h"
#include "MFCtext12(1)View.h"
#include "stdafx.h"
#include "MFCtext12(1).h"
#include "Dlg.h"
#include "afxdialogex.h"


// Dlg 对话框

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


// Dlg 消息处理程序





void Dlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	//this->UpdateData(true);
	//name = name + name + _T("1");
	//UpdateData(false);
}


BOOL Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CMFCtext121Doc* pDoc = ((CMFCtext121View*)((CFrameWnd*)AfxGetMainWnd())->GetActiveView())->GetDocument();
	SetDlgtemText(IDC_EDIT1, pDoc->s1);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
