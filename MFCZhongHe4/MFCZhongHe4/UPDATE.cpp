// UPDATE.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCZhongHe4.h"
#include "UPDATE.h"
#include "afxdialogex.h"


// UPDATE 对话框

IMPLEMENT_DYNAMIC(UPDATE, CDialogEx)

UPDATE::UPDATE(CWnd* pParent /*=NULL*/)
	: CDialogEx(UPDATE::IDD, pParent)
{

}

UPDATE::~UPDATE()
{
}

void UPDATE::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(UPDATE, CDialogEx)
END_MESSAGE_MAP()


// UPDATE 消息处理程序
