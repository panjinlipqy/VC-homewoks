
// MFCtext4(2)View.h : CMFCtext42View 类的接口
//

#pragma once


class CMFCtext42View : public CView
{
protected: // 仅从序列化创建
	CMFCtext42View();
	DECLARE_DYNCREATE(CMFCtext42View)

// 特性
public:
	CMFCtext42Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCtext42View();
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
};

#ifndef _DEBUG  // MFCtext4(2)View.cpp 中的调试版本
inline CMFCtext42Doc* CMFCtext42View::GetDocument() const
   { return reinterpret_cast<CMFCtext42Doc*>(m_pDocument); }
#endif

