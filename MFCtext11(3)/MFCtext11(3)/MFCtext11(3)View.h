
// MFCtext11(3)View.h : CMFCtext113View ��Ľӿ�
//

#pragma once


class CMFCtext113View : public CView
{
protected: // �������л�����
	CMFCtext113View();
	DECLARE_DYNCREATE(CMFCtext113View)

// ����
public:
	CMFCtext113Doc* GetDocument() const;

// ����
public:
	bool set;
	CRect rect;
	CRect r;
	int flag;
	int x1, x2;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCtext113View();
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
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MFCtext11(3)View.cpp �еĵ��԰汾
inline CMFCtext113Doc* CMFCtext113View::GetDocument() const
   { return reinterpret_cast<CMFCtext113Doc*>(m_pDocument); }
#endif

