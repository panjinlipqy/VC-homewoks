
// MFCtext4(2)View.h : CMFCtext42View ��Ľӿ�
//

#pragma once


class CMFCtext42View : public CView
{
protected: // �������л�����
	CMFCtext42View();
	DECLARE_DYNCREATE(CMFCtext42View)

// ����
public:
	CMFCtext42Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCtext42View();
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

#ifndef _DEBUG  // MFCtext4(2)View.cpp �еĵ��԰汾
inline CMFCtext42Doc* CMFCtext42View::GetDocument() const
   { return reinterpret_cast<CMFCtext42Doc*>(m_pDocument); }
#endif

