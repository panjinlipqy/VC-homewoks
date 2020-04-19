
// MFCtext2(3)View.h : CMFCtext23View 类的接口
//

#pragma once


class CMFCtext23View : public CView
{
protected: // 仅从序列化创建
	CMFCtext23View();
	DECLARE_DYNCREATE(CMFCtext23View)

// 特性
public:
	CMFCtext23Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCtext23View();
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
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCtext2(3)View.cpp 中的调试版本
inline CMFCtext23Doc* CMFCtext23View::GetDocument() const
   { return reinterpret_cast<CMFCtext23Doc*>(m_pDocument); }
#endif

