// BigShow.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCZhongHe4.h"
#include "BigShow.h"
#include "afxdialogex.h"


// BigShow 对话框

IMPLEMENT_DYNAMIC(BigShow, CDialogEx)

BigShow::BigShow(CWnd* pParent /*=NULL*/)
	: CDialogEx(BigShow::IDD, pParent)
{

}

BigShow::~BigShow()
{
}

void BigShow::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(BigShow, CDialogEx)
END_MESSAGE_MAP()


// BigShow 消息处理程序
