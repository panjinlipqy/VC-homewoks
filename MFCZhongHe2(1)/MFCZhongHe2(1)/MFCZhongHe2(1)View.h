
// MFCZhongHe2(1)View.h : CMFCZhongHe21View 类的接口
//

#pragma once

class CMFCZhongHe21Set;

class CMFCZhongHe21View : public CRecordView
{
protected: // 仅从序列化创建
	CMFCZhongHe21View();
	DECLARE_DYNCREATE(CMFCZhongHe21View)

public:
	enum{ IDD = IDD_MFCZHONGHE21_FORM };
	CMFCZhongHe21Set* m_pSet;

// 特性
public:
	CMFCZhongHe21Doc* GetDocument() const;

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
	virtual ~CMFCZhongHe21View();
	void draw(CString file);
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
	afx_msg void OnEnChangeEdit2();
	CString name;
	CString id;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
};

#ifndef _DEBUG  // MFCZhongHe2(1)View.cpp 中的调试版本
inline CMFCZhongHe21Doc* CMFCZhongHe21View::GetDocument() const
   { return reinterpret_cast<CMFCZhongHe21Doc*>(m_pDocument); }
#endif

