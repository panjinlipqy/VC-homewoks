#pragma once


// sort �Ի���

class sort : public CDialogEx
{
	DECLARE_DYNAMIC(sort)

public:
	sort(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~sort();

// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
