
// MFCtext6(1)View.h : CMFCtext61View ��Ľӿ�
//

#pragma once


class CMFCtext61View : public CView
{
protected: // �������л�����
	CMFCtext61View();
	DECLARE_DYNCREATE(CMFCtext61View)

// ����
public:
	CMFCtext61Doc* GetDocument() const;

// ����
public:
	int count;
	CString s, s1;
	CPoint p1,p2;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCtext61View();
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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCtext6(1)View.cpp �еĵ��԰汾
inline CMFCtext61Doc* CMFCtext61View::GetDocument() const
   { return reinterpret_cast<CMFCtext61Doc*>(m_pDocument); }
#endif

