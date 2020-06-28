#pragma once


// result 对话框

class result : public CDialogEx
{
	DECLARE_DYNAMIC(result)

public:
	result(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~result();

// 对话框数据
	enum { IDD = IDD_DIALOG7 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
