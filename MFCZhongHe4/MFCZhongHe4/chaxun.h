#pragma once


// chaxun �Ի���

class chaxun : public CDialogEx
{
	DECLARE_DYNAMIC(chaxun)

public:
	chaxun(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~chaxun();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
