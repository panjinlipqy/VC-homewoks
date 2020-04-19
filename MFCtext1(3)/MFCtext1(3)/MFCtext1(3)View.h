
// MFCtext1(3)View.h : CMFCtext13View 类的接口
//

#pragma once


class CMFCtext13View : public CView
{
protected: // 仅从序列化创建
	CMFCtext13View();
	DECLARE_DYNCREATE(CMFCtext13View)

// 特性
public:
	CMFCtext13Doc* GetDocument() const;

// 操作
public:
	CRect cr;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCtext13View();
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
};

#ifndef _DEBUG  // MFCtext1(3)View.cpp 中的调试版本
inline CMFCtext13Doc* CMFCtext13View::GetDocument() const
   { return reinterpret_cast<CMFCtext13Doc*>(m_pDocument); }
#endif

