
// MFCtext10(1)View.h : CMFCtext101View ��Ľӿ�
//

#pragma once


class CMFCtext101View : public CView
{
protected: // �������л�����
	CMFCtext101View();
	DECLARE_DYNCREATE(CMFCtext101View)

// ����
public:
	CMFCtext101Doc* GetDocument() const;

// ����
public:
	CRect r;
	CString h1;
	CPoint p;
	CString c;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCtext101View();
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
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // MFCtext10(1)View.cpp �еĵ��԰汾
inline CMFCtext101Doc* CMFCtext101View::GetDocument() const
   { return reinterpret_cast<CMFCtext101Doc*>(m_pDocument); }
#endif

