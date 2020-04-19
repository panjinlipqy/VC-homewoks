
// MFCtext5View.h : CMFCtext5View ��Ľӿ�
//

#pragma once


class CMFCtext5View : public CView
{
protected: // �������л�����
	CMFCtext5View();
	DECLARE_DYNCREATE(CMFCtext5View)

// ����
public:
	CMFCtext5Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCtext5View();
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

#ifndef _DEBUG  // MFCtext5View.cpp �еĵ��԰汾
inline CMFCtext5Doc* CMFCtext5View::GetDocument() const
   { return reinterpret_cast<CMFCtext5Doc*>(m_pDocument); }
#endif

