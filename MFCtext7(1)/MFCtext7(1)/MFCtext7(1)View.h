
// MFCtext7(1)View.h : CMFCtext71View 类的接口
//

#pragma once


class CMFCtext71View : public CView
{
protected: // 仅从序列化创建
	CMFCtext71View();
	DECLARE_DYNCREATE(CMFCtext71View)

// 特性
public:
	CMFCtext71Doc* GetDocument() const;

// 操作
public:
	CRect R, r;
	CPoint p;
	CArray<CRect, CRect&> ca;
	bool set;
	int n1, n2, n3;
	
	
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCtext71View();
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
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MFCtext7(1)View.cpp 中的调试版本
inline CMFCtext71Doc* CMFCtext71View::GetDocument() const
   { return reinterpret_cast<CMFCtext71Doc*>(m_pDocument); }
#endif

