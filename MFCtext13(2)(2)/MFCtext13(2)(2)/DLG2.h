#pragma once


// DLG2 对话框

class DLG2 : public CDialogEx
{
	DECLARE_DYNAMIC(DLG2)

public:
	DLG2(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DLG2();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int R;
	int G;
	int B;
};
