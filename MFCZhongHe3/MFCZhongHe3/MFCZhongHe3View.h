
// MFCZhongHe3View.h : CMFCZhongHe3View 类的接口
//

#pragma once

class CMFCZhongHe3Set;

class CMFCZhongHe3View : public CRecordView
{
protected: // 仅从序列化创建
	CMFCZhongHe3View();
	DECLARE_DYNCREATE(CMFCZhongHe3View)

public:
	enum{ IDD = IDD_MFCZHONGHE3_FORM };
	CMFCZhongHe3Set* m_pSet;

// 特性
public:
	CMFCZhongHe3Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMFCZhongHe3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	CString text;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};

#ifndef _DEBUG  // MFCZhongHe3View.cpp 中的调试版本
inline CMFCZhongHe3Doc* CMFCZhongHe3View::GetDocument() const
   { return reinterpret_cast<CMFCZhongHe3Doc*>(m_pDocument); }
#endif

