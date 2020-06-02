
// MFCZongHe1View.h : CMFCZongHe1View 类的接口
//

#pragma once

class CMFCZongHe1Set;

class CMFCZongHe1View : public CRecordView
{
protected: // 仅从序列化创建
	CMFCZongHe1View();
	DECLARE_DYNCREATE(CMFCZongHe1View)

public:
	enum{ IDD = IDD_MFCZONGHE1_FORM };
	CMFCZongHe1Set* m_pSet;

// 特性
public:
	CMFCZongHe1Doc* GetDocument() const;
	void draw(CString file);

// 操作
public:
	CString path;

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMFCZongHe1View();
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
	CString name;
	CString id;
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // MFCZongHe1View.cpp 中的调试版本
inline CMFCZongHe1Doc* CMFCZongHe1View::GetDocument() const
   { return reinterpret_cast<CMFCZongHe1Doc*>(m_pDocument); }
#endif

