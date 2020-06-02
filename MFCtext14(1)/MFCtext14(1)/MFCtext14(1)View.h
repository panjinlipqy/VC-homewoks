
// MFCtext14(1)View.h : CMFCtext141View 类的接口
//

#pragma once


class CMFCtext141View : public CView
{
protected: // 仅从序列化创建
	CMFCtext141View();
	DECLARE_DYNCREATE(CMFCtext141View)

// 特性
public:
	CMFCtext141Doc* GetDocument() const;

// 操作
public:
	CString filename;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCtext141View();
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
	afx_msg void OnFileSaveAs();
};

#ifndef _DEBUG  // MFCtext14(1)View.cpp 中的调试版本
inline CMFCtext141Doc* CMFCtext141View::GetDocument() const
   { return reinterpret_cast<CMFCtext141Doc*>(m_pDocument); }
#endif

