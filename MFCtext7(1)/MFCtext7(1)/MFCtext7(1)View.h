
// MFCtext7(1)View.h : CMFCtext71View ��Ľӿ�
//

#pragma once


class CMFCtext71View : public CView
{
protected: // �������л�����
	CMFCtext71View();
	DECLARE_DYNCREATE(CMFCtext71View)

// ����
public:
	CMFCtext71Doc* GetDocument() const;

// ����
public:
	CRect R, r;
	CPoint p;
	CArray<CRect, CRect&> ca;
	bool set;
	int n1, n2, n3;
	
	
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCtext71View();
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
	afx_msg void OnShow();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MFCtext7(1)View.cpp �еĵ��԰汾
inline CMFCtext71Doc* CMFCtext71View::GetDocument() const
   { return reinterpret_cast<CMFCtext71Doc*>(m_pDocument); }
#endif

