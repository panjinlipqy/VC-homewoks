#pragma once


// BigShow �Ի���

class BigShow : public CDialogEx
{
	DECLARE_DYNAMIC(BigShow)

public:
	BigShow(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~BigShow();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
