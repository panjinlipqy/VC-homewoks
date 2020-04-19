
// MFCtext2(2)View.h : CMFCtext22View 类的接口
//

#pragma once


class CMFCtext22View : public CView
{
protected: // 仅从序列化创建
	CMFCtext22View();
	DECLARE_DYNCREATE(CMFCtext22View)

// 特性
public:
	CMFCtext22Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCtext22View();
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

#ifndef _DEBUG  // MFCtext2(2)View.cpp 中的调试版本
inline CMFCtext22Doc* CMFCtext22View::GetDocument() const
   { return reinterpret_cast<CMFCtext22Doc*>(m_pDocument); }
#endif

