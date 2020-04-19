
// MFCtext8View.h : CMFCtext8View 类的接口
//

#pragma once


class CMFCtext8View : public CView
{
protected: // 仅从序列化创建
	CMFCtext8View();
	DECLARE_DYNCREATE(CMFCtext8View)

// 特性
public:
	CMFCtext8Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCtext8View();
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
	afx_msg void OnShow();
};

#ifndef _DEBUG  // MFCtext8View.cpp 中的调试版本
inline CMFCtext8Doc* CMFCtext8View::GetDocument() const
   { return reinterpret_cast<CMFCtext8Doc*>(m_pDocument); }
#endif

