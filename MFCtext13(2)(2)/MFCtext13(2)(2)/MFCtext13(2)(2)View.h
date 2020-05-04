
// MFCtext13(2)(2)View.h : CMFCtext1322View 类的接口
//

#pragma once


class CMFCtext1322View : public CView
{
protected: // 仅从序列化创建
	CMFCtext1322View();
	DECLARE_DYNCREATE(CMFCtext1322View)

// 特性
public:
	CMFCtext1322Doc* GetDocument() const;

// 操作
public:
	int a;
	int b;
	int x;
	int y;
	CRect re;
	int flag;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCtext1322View();
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
	afx_msg void OnPop();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnClor();
};

#ifndef _DEBUG  // MFCtext13(2)(2)View.cpp 中的调试版本
inline CMFCtext1322Doc* CMFCtext1322View::GetDocument() const
   { return reinterpret_cast<CMFCtext1322Doc*>(m_pDocument); }
#endif

