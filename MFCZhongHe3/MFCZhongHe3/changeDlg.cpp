// changeDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCZhongHe3.h"
#include "changeDlg.h"
#include "afxdialogex.h"


// changeDlg 对话框

IMPLEMENT_DYNAMIC(changeDlg, CDialogEx)

changeDlg::changeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(changeDlg::IDD, pParent)
	, t(0)
{

}

changeDlg::~changeDlg()
{
}

void changeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, t);
}


BEGIN_MESSAGE_MAP(changeDlg, CDialogEx)
END_MESSAGE_MAP()


// changeDlg 消息处理程序
