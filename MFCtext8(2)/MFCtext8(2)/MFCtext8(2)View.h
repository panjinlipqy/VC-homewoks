
// MFCtext8(2)View.h : CMFCtext82View 类的接口
//

#pragma once


class CMFCtext82View : public CView
{
protected: // 仅从序列化创建
	CMFCtext82View();
	DECLARE_DYNCREATE(CMFCtext82View)

// 特性
public:
	CMFCtext82Doc* GetDocument() const;

// 操作
public:
	CBitmap m_Bitmap;
	int m_nWidth;
	int m_nHeight;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCtext82View();
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
	afx_msg void OnShowImg();
};

#ifndef _DEBUG  // MFCtext8(2)View.cpp 中的调试版本
inline CMFCtext82Doc* CMFCtext82View::GetDocument() const
   { return reinterpret_cast<CMFCtext82Doc*>(m_pDocument); }
#endif

