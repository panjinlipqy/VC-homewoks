
// MFCtext11(2)View.h : CMFCtext112View 类的接口
//
#include "Dlg.h"
#pragma once


class CMFCtext112View : public CView
{
protected: // 仅从序列化创建
	CMFCtext112View();
	DECLARE_DYNCREATE(CMFCtext112View)

// 特性
public:
	CMFCtext112Doc* GetDocument() const;

// 操作
public:
	int a, b, c;
	Dlg  *pD;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCtext112View();
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

#ifndef _DEBUG  // MFCtext11(2)View.cpp 中的调试版本
inline CMFCtext112Doc* CMFCtext112View::GetDocument() const
   { return reinterpret_cast<CMFCtext112Doc*>(m_pDocument); }
#endif

