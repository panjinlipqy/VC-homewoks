
// MFCtext(2)View.h : CMFCtext2View 类的接口
//

#pragma once


class CMFCtext2View : public CView
{
protected: // 仅从序列化创建
	CMFCtext2View();
	DECLARE_DYNCREATE(CMFCtext2View)

// 特性
public:
	CMFCtext2Doc* GetDocument() const;

// 操作
public:
	CRect r;
	CPoint p;
	CPoint pn;
	CPoint ps;
	bool flag;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCtext2View();
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
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
};

#ifndef _DEBUG  // MFCtext(2)View.cpp 中的调试版本
inline CMFCtext2Doc* CMFCtext2View::GetDocument() const
   { return reinterpret_cast<CMFCtext2Doc*>(m_pDocument); }
#endif

