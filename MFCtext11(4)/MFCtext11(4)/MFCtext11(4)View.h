
// MFCtext11(4)View.h : CMFCtext114View ��Ľӿ�
//
#include "MyDlg.h"
#pragma once


class CMFCtext114View : public CView
{
protected: // �������л�����
	CMFCtext114View();
	DECLARE_DYNCREATE(CMFCtext114View)

// ����
public:
	CMFCtext114Doc* GetDocument() const;

// ����
public:
	MyDlg dlg;
	int t;
	CString a, c, b1;
	int b;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCtext114View();
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
	afx_msg void OnPop();
};

#ifndef _DEBUG  // MFCtext11(4)View.cpp �еĵ��԰汾
inline CMFCtext114Doc* CMFCtext114View::GetDocument() const
   { return reinterpret_cast<CMFCtext114Doc*>(m_pDocument); }
#endif

