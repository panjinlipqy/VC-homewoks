
// MFCtext13（1）Dlg.h : 头文件
//

#pragma once


// CMFCtext13（1）Dlg 对话框
class CMFCtext13（1）Dlg : public CDialogEx
{
// 构造
public:
	CMFCtext13（1）Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFCTEXT131_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	
	void SaveFirstValue(); //保存第一个输入值
	void Calculator(); //计算

	CString mstr;      //编辑框内的字符串
	double mNum1;      //输入的2个值
	double mNum2;
	char mFlag;       //运算符号
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
