
// MFCtext1(1)View.h : CMFCtext11View ��Ľӿ�
//

#pragma once


class CMFCtext11View : public CView
{
protected: // �������л�����
	CMFCtext11View();
	DECLARE_DYNCREATE(CMFCtext11View)

// ����
public:
	CMFCtext11Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCtext11View();
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

#ifndef _DEBUG  // MFCtext1(1)View.cpp �еĵ��԰汾
inline CMFCtext11Doc* CMFCtext11View::GetDocument() const
   { return reinterpret_cast<CMFCtext11Doc*>(m_pDocument); }
#endif

