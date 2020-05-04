
// MFCtext13(2)(1)View.h : CMFCtext1321View 类的接口
//

#pragma once


class CMFCtext1321View : public CView
{
protected: // 仅从序列化创建
	CMFCtext1321View();
	DECLARE_DYNCREATE(CMFCtext1321View)

// 特性
public:
	CMFCtext1321Doc* GetDocument() const;

// 操作
public:
	CPoint ps;
	CPoint pe;
	CPoint pt;
	CRect rs;
	CRect re;
	bool set;
	int flag;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCtext1321View();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCtext13(2)(1)View.cpp 中的调试版本
inline CMFCtext1321Doc* CMFCtext1321View::GetDocument() const
   { return reinterpret_cast<CMFCtext1321Doc*>(m_pDocument); }
#endif

