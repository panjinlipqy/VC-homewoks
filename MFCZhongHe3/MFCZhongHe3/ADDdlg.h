#pragma once


// ADDdlg �Ի���

class ADDdlg : public CDialogEx
{
	DECLARE_DYNAMIC(ADDdlg)

public:
	ADDdlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ADDdlg();

// �Ի�������
	enum { IDD = IDD_ADD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	long i;
};
