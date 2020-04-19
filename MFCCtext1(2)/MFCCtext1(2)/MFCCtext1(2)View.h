
// MFCCtext1(2)View.h : CMFCCtext12View 类的接口
//

#pragma once


class CMFCCtext12View : public CView
{
protected: // 仅从序列化创建
	CMFCCtext12View();
	DECLARE_DYNCREATE(CMFCCtext12View)

// 特性
public:
	CMFCCtext12Doc* GetDocument() const;

// 操作
public:
	CRect r;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCCtext12View();
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

#ifndef _DEBUG  // MFCCtext1(2)View.cpp 中的调试版本
inline CMFCCtext12Doc* CMFCCtext12View::GetDocument() const
   { return reinterpret_cast<CMFCCtext12Doc*>(m_pDocument); }
#endif

