
// MFCtext(2)View.h : CMFCtext2View ��Ľӿ�
//

#pragma once


class CMFCtext2View : public CView
{
protected: // �������л�����
	CMFCtext2View();
	DECLARE_DYNCREATE(CMFCtext2View)

// ����
public:
	CMFCtext2Doc* GetDocument() const;

// ����
public:
	CRect r;
	CPoint p;
	CPoint pn;
	CPoint ps;
	bool flag;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCtext2View();
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
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
};

#ifndef _DEBUG  // MFCtext(2)View.cpp �еĵ��԰汾
inline CMFCtext2Doc* CMFCtext2View::GetDocument() const
   { return reinterpret_cast<CMFCtext2Doc*>(m_pDocument); }
#endif

