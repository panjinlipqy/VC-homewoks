#pragma once


// UPDATE 对话框

class UPDATE : public CDialogEx
{
	DECLARE_DYNAMIC(UPDATE)

public:
	UPDATE(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~UPDATE();

// 对话框数据
	enum { IDD = IDD_DIALOG6 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
