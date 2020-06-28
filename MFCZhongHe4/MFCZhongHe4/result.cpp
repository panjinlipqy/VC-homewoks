// result.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCZhongHe4.h"
#include "result.h"
#include "afxdialogex.h"


// result 对话框

IMPLEMENT_DYNAMIC(result, CDialogEx)

result::result(CWnd* pParent /*=NULL*/)
	: CDialogEx(result::IDD, pParent)
{

}

result::~result()
{
}

void result::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(result, CDialogEx)
END_MESSAGE_MAP()


// result 消息处理程序
