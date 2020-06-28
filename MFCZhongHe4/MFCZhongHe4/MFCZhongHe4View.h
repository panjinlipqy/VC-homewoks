
// MFCZhongHe4View.h : CMFCZhongHe4View 类的接口
//

#pragma once

class CMFCZhongHe4Set;

class CMFCZhongHe4View : public CRecordView
{
protected: // 仅从序列化创建
	CMFCZhongHe4View();
	DECLARE_DYNCREATE(CMFCZhongHe4View)

public:
	enum{ IDD = IDD_MFCZHONGHE4_FORM };
	CMFCZhongHe4Set* m_pSet;

// 特性
public:
	CMFCZhongHe4Doc* GetDocument() const;
	void draw(CString file);

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
	virtual ~CMFCZhongHe4View();
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
	CString number;
	CString name;
	CString sex;
	CString mon;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
};

#ifndef _DEBUG  // MFCZhongHe4View.cpp 中的调试版本
inline CMFCZhongHe4Doc* CMFCZhongHe4View::GetDocument() const
   { return reinterpret_cast<CMFCZhongHe4Doc*>(m_pDocument); }
#endif

