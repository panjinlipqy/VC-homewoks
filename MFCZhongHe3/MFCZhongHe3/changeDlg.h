#pragma once


// changeDlg �Ի���

class changeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(changeDlg)

public:
	changeDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~changeDlg();

// �Ի�������
	enum { IDD = IDD_change };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	long t;
};
