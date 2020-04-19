
// MFCtext6(2)View.h : CMFCtext62View 类的接口
//

#pragma once


class CMFCtext62View : public CView
{
protected: // 仅从序列化创建
	CMFCtext62View();
	DECLARE_DYNCREATE(CMFCtext62View)

// 特性
public:
	CMFCtext62Doc* GetDocument() const;

// 操作
public:
	CRect r, R;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCtext62View();
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
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // MFCtext6(2)View.cpp 中的调试版本
inline CMFCtext62Doc* CMFCtext62View::GetDocument() const
   { return reinterpret_cast<CMFCtext62Doc*>(m_pDocument); }
#endif

