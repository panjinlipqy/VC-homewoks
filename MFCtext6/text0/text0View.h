
// text0View.h : Ctext0View ��Ľӿ�
//

#pragma once


class Ctext0View : public CView
{
protected: // �������л�����
	Ctext0View();
	DECLARE_DYNCREATE(Ctext0View)

// ����
public:
	Ctext0Doc* GetDocument() const;

// ����
public:
	int N;
	CArray<CRect, CRect> cr;
	CRect r;
	bool set;
	CRect rect;
	CArray<int> y;


// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Ctext0View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // text0View.cpp �еĵ��԰汾
inline Ctext0Doc* Ctext0View::GetDocument() const
   { return reinterpret_cast<Ctext0Doc*>(m_pDocument); }
#endif

