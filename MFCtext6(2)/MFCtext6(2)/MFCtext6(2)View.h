
// MFCtext6(2)View.h : CMFCtext62View ��Ľӿ�
//

#pragma once


class CMFCtext62View : public CView
{
protected: // �������л�����
	CMFCtext62View();
	DECLARE_DYNCREATE(CMFCtext62View)

// ����
public:
	CMFCtext62Doc* GetDocument() const;

// ����
public:
	CRect r, R;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCtext62View();
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
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // MFCtext6(2)View.cpp �еĵ��԰汾
inline CMFCtext62Doc* CMFCtext62View::GetDocument() const
   { return reinterpret_cast<CMFCtext62Doc*>(m_pDocument); }
#endif

