#pragma once


// DLG2 �Ի���

class DLG2 : public CDialogEx
{
	DECLARE_DYNAMIC(DLG2)

public:
	DLG2(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DLG2();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int R;
	int G;
	int B;
};
