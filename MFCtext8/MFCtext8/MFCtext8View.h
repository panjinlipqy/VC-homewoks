
// MFCtext8View.h : CMFCtext8View ��Ľӿ�
//

#pragma once


class CMFCtext8View : public CView
{
protected: // �������л�����
	CMFCtext8View();
	DECLARE_DYNCREATE(CMFCtext8View)

// ����
public:
	CMFCtext8Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCtext8View();
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
};

#ifndef _DEBUG  // MFCtext8View.cpp �еĵ��԰汾
inline CMFCtext8Doc* CMFCtext8View::GetDocument() const
   { return reinterpret_cast<CMFCtext8Doc*>(m_pDocument); }
#endif

