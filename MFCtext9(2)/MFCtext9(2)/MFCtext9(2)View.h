
// MFCtext9(2)View.h : CMFCtext92View 类的接口
//

#pragma once


class CMFCtext92View : public CView
{
protected: // 仅从序列化创建
	CMFCtext92View();
	DECLARE_DYNCREATE(CMFCtext92View)

// 特性
public:
	CMFCtext92Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCtext92View();
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
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // MFCtext9(2)View.cpp 中的调试版本
inline CMFCtext92Doc* CMFCtext92View::GetDocument() const
   { return reinterpret_cast<CMFCtext92Doc*>(m_pDocument); }
#endif

