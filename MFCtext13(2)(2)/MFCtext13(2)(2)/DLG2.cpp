// DLG2.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCtext13(2)(2).h"
#include "DLG2.h"
#include "afxdialogex.h"


// DLG2 对话框

IMPLEMENT_DYNAMIC(DLG2, CDialogEx)

DLG2::DLG2(CWnd* pParent /*=NULL*/)
	: CDialogEx(DLG2::IDD, pParent)
	, R(0)
	, G(0)
	, B(0)
{

}

DLG2::~DLG2()
{
}

void DLG2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT5, R);
	DDX_Text(pDX, IDC_EDIT6, G);
	DDX_Text(pDX, IDC_EDIT7, B);
}


BEGIN_MESSAGE_MAP(DLG2, CDialogEx)
END_MESSAGE_MAP()


// DLG2 消息处理程序
