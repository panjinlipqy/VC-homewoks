#pragma once


// result �Ի���

class result : public CDialogEx
{
	DECLARE_DYNAMIC(result)

public:
	result(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~result();

// �Ի�������
	enum { IDD = IDD_DIALOG7 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
