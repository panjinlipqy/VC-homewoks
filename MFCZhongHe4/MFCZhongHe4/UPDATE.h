#pragma once


// UPDATE �Ի���

class UPDATE : public CDialogEx
{
	DECLARE_DYNAMIC(UPDATE)

public:
	UPDATE(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~UPDATE();

// �Ի�������
	enum { IDD = IDD_DIALOG6 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
