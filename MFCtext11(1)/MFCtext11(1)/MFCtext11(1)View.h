
// MFCtext11(1)View.h : CMFCtext111View ��Ľӿ�
//

#pragma once


class CMFCtext111View : public CView
{
protected: // �������л�����
	CMFCtext111View();
	DECLARE_DYNCREATE(CMFCtext111View)

// ����
public:
	CMFCtext111Doc* GetDocument() const;

// ����
public:
	CRect r;
	CPoint p, p1;
	int x, y;
	int Flag;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCtext111View();
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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCtext11(1)View.cpp �еĵ��԰汾
inline CMFCtext111Doc* CMFCtext111View::GetDocument() const
   { return reinterpret_cast<CMFCtext111Doc*>(m_pDocument); }
#endif

