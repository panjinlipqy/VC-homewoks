
// MFCtext12(1)View.h : CMFCtext121View 类的接口
//
#include "Dlg.h"
#pragma once


class CMFCtext121View : public CView
{
protected: // 仅从序列化创建
	CMFCtext121View();
	DECLARE_DYNCREATE(CMFCtext121View)

// 特性
public:
	CMFCtext121Doc* GetDocument() const;

// 操作
public:
	int flag;
	CString s1;
	Dlg  *pD;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCtext121View();
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
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnFileOpen();
	afx_msg void OnPop();
};

#ifndef _DEBUG  // MFCtext12(1)View.cpp 中的调试版本
inline CMFCtext121Doc* CMFCtext121View::GetDocument() const
   { return reinterpret_cast<CMFCtext121Doc*>(m_pDocument); }
#endif

