
// MFCtext8(3)View.h : CMFCtext83View 类的接口
//

#pragma once


class CMFCtext83View : public CView
{
protected: // 仅从序列化创建
	CMFCtext83View();
	DECLARE_DYNCREATE(CMFCtext83View)

// 特性
public:
	CMFCtext83Doc* GetDocument() const;

// 操作
public:
	CPoint sp, ep;
	bool set;
	int flag;
	CRect r;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCtext83View();
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
	afx_msg void Onshowline();
	afx_msg void Onshowrect();
	afx_msg void Onshowelispse();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCtext8(3)View.cpp 中的调试版本
inline CMFCtext83Doc* CMFCtext83View::GetDocument() const
   { return reinterpret_cast<CMFCtext83Doc*>(m_pDocument); }
#endif

