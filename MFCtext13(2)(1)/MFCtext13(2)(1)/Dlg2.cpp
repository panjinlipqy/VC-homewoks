// Dlg2.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCtext13(2)(1).h"
#include "Dlg2.h"
#include "afxdialogex.h"


// Dlg2 对话框

IMPLEMENT_DYNAMIC(Dlg2, CDialogEx)

Dlg2::Dlg2(CWnd* pParent /*=NULL*/)
	: CDialogEx(Dlg2::IDD, pParent)
	, R(0)
	, G(0)
	, B(0)
{

}

Dlg2::~Dlg2()
{
}

void Dlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, R);
	DDX_Text(pDX, IDC_EDIT2, G);
	DDX_Text(pDX, IDC_EDIT3, B);
}


BEGIN_MESSAGE_MAP(Dlg2, CDialogEx)
END_MESSAGE_MAP()


// Dlg2 消息处理程序
