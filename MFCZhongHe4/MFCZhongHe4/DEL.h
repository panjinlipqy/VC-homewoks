#pragma once


// DEL �Ի���

class DEL : public CDialogEx
{
	DECLARE_DYNAMIC(DEL)

public:
	DEL(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DEL();

// �Ի�������
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
