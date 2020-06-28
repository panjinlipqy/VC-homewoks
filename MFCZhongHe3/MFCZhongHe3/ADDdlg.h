#pragma once


// ADDdlg 对话框

class ADDdlg : public CDialogEx
{
	DECLARE_DYNAMIC(ADDdlg)

public:
	ADDdlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ADDdlg();

// 对话框数据
	enum { IDD = IDD_ADD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	long i;
};
