
// MFCZongHe1(2)View.h : CMFCZongHe12View 类的接口
//

#pragma once

class CMFCZongHe12Set;

class CMFCZongHe12View : public CRecordView
{
protected: // 仅从序列化创建
	CMFCZongHe12View();
	DECLARE_DYNCREATE(CMFCZongHe12View)

public:
	enum{ IDD = IDD_MFCZONGHE12_FORM };
	CMFCZongHe12Set* m_pSet;

// 特性
public:
	CMFCZongHe12Doc* GetDocument() const;
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
	virtual ~CMFCZongHe12View();
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
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
};

#ifndef _DEBUG  // MFCZongHe1(2)View.cpp 中的调试版本
inline CMFCZongHe12Doc* CMFCZongHe12View::GetDocument() const
   { return reinterpret_cast<CMFCZongHe12Doc*>(m_pDocument); }
#endif

