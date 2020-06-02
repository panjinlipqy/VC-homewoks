#pragma once
#include "afxwin.h"


// MyDlg 对话框

class MyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlg)

public:
	MyDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MyDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString filename;
	CListBox Lbox;
	CString s;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	CString cs;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedOk();
};
