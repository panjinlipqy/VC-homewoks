#pragma once


// Dlg 对话框

class Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Dlg)

public:
	Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Dlg();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString s;
	CString name;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton2();
	virtual BOOL OnInitDialog();
};
