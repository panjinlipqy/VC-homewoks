
// MFCtext13(2)(1)View.h : CMFCtext1321View ��Ľӿ�
//

#pragma once


class CMFCtext1321View : public CView
{
protected: // �������л�����
	CMFCtext1321View();
	DECLARE_DYNCREATE(CMFCtext1321View)

// ����
public:
	CMFCtext1321Doc* GetDocument() const;

// ����
public:
	CPoint ps;
	CPoint pe;
	CPoint pt;
	CRect rs;
	CRect re;
	bool set;
	int flag;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCtext1321View();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCtext13(2)(1)View.cpp �еĵ��԰汾
inline CMFCtext1321Doc* CMFCtext1321View::GetDocument() const
   { return reinterpret_cast<CMFCtext1321Doc*>(m_pDocument); }
#endif

