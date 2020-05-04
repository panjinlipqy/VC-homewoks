
// MFCtext11(1)View.h : CMFCtext111View 类的接口
//

#pragma once


class CMFCtext111View : public CView
{
protected: // 仅从序列化创建
	CMFCtext111View();
	DECLARE_DYNCREATE(CMFCtext111View)

// 特性
public:
	CMFCtext111Doc* GetDocument() const;

// 操作
public:
	CRect r;
	CPoint p, p1;
	int x, y;
	int Flag;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCtext111View();
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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCtext11(1)View.cpp 中的调试版本
inline CMFCtext111Doc* CMFCtext111View::GetDocument() const
   { return reinterpret_cast<CMFCtext111Doc*>(m_pDocument); }
#endif

