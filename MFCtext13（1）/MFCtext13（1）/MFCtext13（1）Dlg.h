
// MFCtext13��1��Dlg.h : ͷ�ļ�
//

#pragma once


// CMFCtext13��1��Dlg �Ի���
class CMFCtext13��1��Dlg : public CDialogEx
{
// ����
public:
	CMFCtext13��1��Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCTEXT131_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	
	void SaveFirstValue(); //�����һ������ֵ
	void Calculator(); //����

	CString mstr;      //�༭���ڵ��ַ���
	double mNum1;      //�����2��ֵ
	double mNum2;
	char mFlag;       //�������
	//CALCULATOR_FLAG flag;

	afx_msg void OnBnClicked1();
	afx_msg void OnBnClicked2();
	afx_msg void OnBnClicked3();
	afx_msg void OnBnClicked4();
	afx_msg void OnBnClicked5();
	afx_msg void OnBnClicked6();
	afx_msg void OnBnClicked7();
	afx_msg void OnBnClicked8();
	afx_msg void OnBnClicked9();
	afx_msg void OnBnClicked0();
	afx_msg void OnBnClickedpoint();
	afx_msg void OnBnClickedequal();
	afx_msg void OnBnClickedadd();
	afx_msg void OnBnClickedminus();
	afx_msg void OnBnClickedtimes();
	afx_msg void OnBnClickeddivide();
	afx_msg void OnBnClickedsquare();
	afx_msg void OnBnClickedreci();
	afx_msg void OnBnClickedempty();
	afx_msg void OnBnClickeddel();
};
