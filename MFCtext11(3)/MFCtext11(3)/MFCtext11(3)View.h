
// MFCtext11(3)View.h : CMFCtext113View 类的接口
//

#pragma once


class CMFCtext113View : public CView
{
protected: // 仅从序列化创建
	CMFCtext113View();
	DECLARE_DYNCREATE(CMFCtext113View)

// 特性
public:
	CMFCtext113Doc* GetDocument() const;

// 操作
public:
	bool set;
	CRect rect;
	CRect r;
	int flag;
	int x1, x2;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCtext113View();
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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MFCtext11(3)View.cpp 中的调试版本
inline CMFCtext113Doc* CMFCtext113View::GetDocument() const
   { return reinterpret_cast<CMFCtext113Doc*>(m_pDocument); }
#endif

