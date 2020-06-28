// ADD.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCZhongHe4.h"
#include "ADD.h"
#include "afxdialogex.h"


// ADD 对话框

IMPLEMENT_DYNAMIC(ADD, CDialogEx)

ADD::ADD(CWnd* pParent /*=NULL*/)
	: CDialogEx(ADD::IDD, pParent)
{

}

ADD::~ADD()
{
}

void ADD::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ADD, CDialogEx)
END_MESSAGE_MAP()


// ADD 消息处理程序
