
// MFCtext3View.h : CMFCtext3View ��Ľӿ�
//

#pragma once


class CMFCtext3View : public CView
{
protected: // �������л�����
	CMFCtext3View();
	DECLARE_DYNCREATE(CMFCtext3View)

// ����
public:
	CMFCtext3Doc* GetDocument() const;

// ����
public:
	CRect cr;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCtext3View();
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
};

#ifndef _DEBUG  // MFCtext3View.cpp �еĵ��԰汾
inline CMFCtext3Doc* CMFCtext3View::GetDocument() const
   { return reinterpret_cast<CMFCtext3Doc*>(m_pDocument); }
#endif

