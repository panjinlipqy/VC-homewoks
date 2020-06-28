#pragma once


// DEL 对话框

class DEL : public CDialogEx
{
	DECLARE_DYNAMIC(DEL)

public:
	DEL(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DEL();

// 对话框数据
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
