
// MFCtext12(1)View.h : CMFCtext121View ��Ľӿ�
//
#include "Dlg.h"
#pragma once


class CMFCtext121View : public CView
{
protected: // �������л�����
	CMFCtext121View();
	DECLARE_DYNCREATE(CMFCtext121View)

// ����
public:
	CMFCtext121Doc* GetDocument() const;

// ����
public:
	int flag;
	CString s1;
	Dlg  *pD;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCtext121View();
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
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnFileOpen();
	afx_msg void OnPop();
};

#ifndef _DEBUG  // MFCtext12(1)View.cpp �еĵ��԰汾
inline CMFCtext121Doc* CMFCtext121View::GetDocument() const
   { return reinterpret_cast<CMFCtext121Doc*>(m_pDocument); }
#endif

