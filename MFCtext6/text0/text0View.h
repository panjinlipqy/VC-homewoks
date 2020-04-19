
// text0View.h : Ctext0View 类的接口
//

#pragma once


class Ctext0View : public CView
{
protected: // 仅从序列化创建
	Ctext0View();
	DECLARE_DYNCREATE(Ctext0View)

// 特性
public:
	Ctext0Doc* GetDocument() const;

// 操作
public:
	int N;
	CArray<CRect, CRect> cr;
	CRect r;
	bool set;
	CRect rect;
	CArray<int> y;


// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Ctext0View();
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
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // text0View.cpp 中的调试版本
inline Ctext0Doc* Ctext0View::GetDocument() const
   { return reinterpret_cast<Ctext0Doc*>(m_pDocument); }
#endif

