
// MFCtext10(1)View.h : CMFCtext101View 类的接口
//

#pragma once


class CMFCtext101View : public CView
{
protected: // 仅从序列化创建
	CMFCtext101View();
	DECLARE_DYNCREATE(CMFCtext101View)

// 特性
public:
	CMFCtext101Doc* GetDocument() const;

// 操作
public:
	CRect r;
	CString h1;
	CPoint p;
	CString c;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCtext101View();
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
};

#ifndef _DEBUG  // MFCtext10(1)View.cpp 中的调试版本
inline CMFCtext101Doc* CMFCtext101View::GetDocument() const
   { return reinterpret_cast<CMFCtext101Doc*>(m_pDocument); }
#endif

