#pragma once


// Dlg �Ի���

class Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Dlg)

public:
	Dlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Dlg();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int a;
	int b;
	int c;
	afx_msg void OnBnClickedButton1();
};
