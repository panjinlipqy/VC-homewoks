
// MFCtext14实验2View.h : CMFCtext14实验2View 类的接口
//

#pragma once


class CMFCtext14实验2View : public CView
{
protected: // 仅从序列化创建
	CMFCtext14实验2View();
	DECLARE_DYNCREATE(CMFCtext14实验2View)

// 特性
public:
	CMFCtext14实验2Doc* GetDocument() const;

// 操作
public:
	CPoint ps,pe;
	bool set;
	CRect re;
	int flag;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCtext14实验2View();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MFCtext14实验2View.cpp 中的调试版本
inline CMFCtext14实验2Doc* CMFCtext14实验2View::GetDocument() const
   { return reinterpret_cast<CMFCtext14实验2Doc*>(m_pDocument); }
#endif

