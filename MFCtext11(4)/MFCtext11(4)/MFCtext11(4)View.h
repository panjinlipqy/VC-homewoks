
// MFCtext11(4)View.h : CMFCtext114View 类的接口
//
#include "MyDlg.h"
#pragma once


class CMFCtext114View : public CView
{
protected: // 仅从序列化创建
	CMFCtext114View();
	DECLARE_DYNCREATE(CMFCtext114View)

// 特性
public:
	CMFCtext114Doc* GetDocument() const;

// 操作
public:
	MyDlg dlg;
	int t;
	CString a, c, b1;
	int b;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCtext114View();
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
	afx_msg void OnPop();
};

#ifndef _DEBUG  // MFCtext11(4)View.cpp 中的调试版本
inline CMFCtext114Doc* CMFCtext114View::GetDocument() const
   { return reinterpret_cast<CMFCtext114Doc*>(m_pDocument); }
#endif

