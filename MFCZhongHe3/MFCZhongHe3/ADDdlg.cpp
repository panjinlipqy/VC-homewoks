// ADDdlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCZhongHe3.h"
#include "ADDdlg.h"
#include "afxdialogex.h"


// ADDdlg 对话框

IMPLEMENT_DYNAMIC(ADDdlg, CDialogEx)

ADDdlg::ADDdlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ADDdlg::IDD, pParent)
	, i(0)
{

}

ADDdlg::~ADDdlg()
{
}

void ADDdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, i);
}


BEGIN_MESSAGE_MAP(ADDdlg, CDialogEx)
END_MESSAGE_MAP()


// ADDdlg 消息处理程序
