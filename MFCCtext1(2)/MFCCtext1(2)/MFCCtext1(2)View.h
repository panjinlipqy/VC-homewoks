
// MFCCtext1(2)View.h : CMFCCtext12View ��Ľӿ�
//

#pragma once


class CMFCCtext12View : public CView
{
protected: // �������л�����
	CMFCCtext12View();
	DECLARE_DYNCREATE(CMFCCtext12View)

// ����
public:
	CMFCCtext12Doc* GetDocument() const;

// ����
public:
	CRect r;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCCtext12View();
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

#ifndef _DEBUG  // MFCCtext1(2)View.cpp �еĵ��԰汾
inline CMFCCtext12Doc* CMFCCtext12View::GetDocument() const
   { return reinterpret_cast<CMFCCtext12Doc*>(m_pDocument); }
#endif

