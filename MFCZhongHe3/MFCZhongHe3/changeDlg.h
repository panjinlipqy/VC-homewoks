#pragma once


// changeDlg 对话框

class changeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(changeDlg)

public:
	changeDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~changeDlg();

// 对话框数据
	enum { IDD = IDD_change };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	long t;
};
