
// MFCtext14ʵ��1View.h : CMFCtext14ʵ��1View ��Ľӿ�
//

#pragma once


class CMFCtext14ʵ��1View : public CView
{
protected: // �������л�����
	CMFCtext14ʵ��1View();
	DECLARE_DYNCREATE(CMFCtext14ʵ��1View)

// ����
public:
	CMFCtext14ʵ��1Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCtext14ʵ��1View();
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
};

#ifndef _DEBUG  // MFCtext14ʵ��1View.cpp �еĵ��԰汾
inline CMFCtext14ʵ��1Doc* CMFCtext14ʵ��1View::GetDocument() const
   { return reinterpret_cast<CMFCtext14ʵ��1Doc*>(m_pDocument); }
#endif

