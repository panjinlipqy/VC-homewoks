
// MFCtext11(2)View.h : CMFCtext112View ��Ľӿ�
//
#include "Dlg.h"
#pragma once


class CMFCtext112View : public CView
{
protected: // �������л�����
	CMFCtext112View();
	DECLARE_DYNCREATE(CMFCtext112View)

// ����
public:
	CMFCtext112Doc* GetDocument() const;

// ����
public:
	int a, b, c;
	Dlg  *pD;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCtext112View();
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

#ifndef _DEBUG  // MFCtext11(2)View.cpp �еĵ��԰汾
inline CMFCtext112Doc* CMFCtext112View::GetDocument() const
   { return reinterpret_cast<CMFCtext112Doc*>(m_pDocument); }
#endif

