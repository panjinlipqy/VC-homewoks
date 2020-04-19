
// MFCtext4(3)View.h : CMFCtext43View 类的接口
//

#pragma once


class CMFCtext43View : public CView
{
protected: // 仅从序列化创建
	CMFCtext43View();
	DECLARE_DYNCREATE(CMFCtext43View)

// 特性
public:
	CMFCtext43Doc* GetDocument() const;

// 操作
public:
	int a,b,c,count;
	CString s1, s2, s3, s4, f1, f2, f3, f4;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCtext43View();
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

#ifndef _DEBUG  // MFCtext4(3)View.cpp 中的调试版本
inline CMFCtext43Doc* CMFCtext43View::GetDocument() const
   { return reinterpret_cast<CMFCtext43Doc*>(m_pDocument); }
#endif

