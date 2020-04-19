
// MFCtext6View.h : CMFCtext6View 类的接口
//

#pragma once


class CMFCtext6View : public CView
{
protected: // 仅从序列化创建
	CMFCtext6View();
	DECLARE_DYNCREATE(CMFCtext6View)

// 特性
public:
	CMFCtext6Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCtext6View();
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

#ifndef _DEBUG  // MFCtext6View.cpp 中的调试版本
inline CMFCtext6Doc* CMFCtext6View::GetDocument() const
   { return reinterpret_cast<CMFCtext6Doc*>(m_pDocument); }
#endif

