
// MFCtext14ʵ��2View.h : CMFCtext14ʵ��2View ��Ľӿ�
//

#pragma once


class CMFCtext14ʵ��2View : public CView
{
protected: // �������л�����
	CMFCtext14ʵ��2View();
	DECLARE_DYNCREATE(CMFCtext14ʵ��2View)

// ����
public:
	CMFCtext14ʵ��2Doc* GetDocument() const;

// ����
public:
	CPoint ps,pe;
	bool set;
	CRect re;
	int flag;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCtext14ʵ��2View();
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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MFCtext14ʵ��2View.cpp �еĵ��԰汾
inline CMFCtext14ʵ��2Doc* CMFCtext14ʵ��2View::GetDocument() const
   { return reinterpret_cast<CMFCtext14ʵ��2Doc*>(m_pDocument); }
#endif

