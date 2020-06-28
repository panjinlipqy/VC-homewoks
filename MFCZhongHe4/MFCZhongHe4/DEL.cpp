// DEL.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCZhongHe4.h"
#include "DEL.h"
#include "afxdialogex.h"


// DEL 对话框

IMPLEMENT_DYNAMIC(DEL, CDialogEx)

DEL::DEL(CWnd* pParent /*=NULL*/)
	: CDialogEx(DEL::IDD, pParent)
{

}

DEL::~DEL()
{
}

void DEL::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DEL, CDialogEx)
END_MESSAGE_MAP()


// DEL 消息处理程序
