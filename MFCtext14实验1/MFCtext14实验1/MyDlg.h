#pragma once
#include "afxwin.h"


// MyDlg �Ի���

class MyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MyDlg)

public:
	MyDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
