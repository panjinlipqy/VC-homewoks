
// MFCtext4View.h : CMFCtext4View ��Ľӿ�
//

#pragma once


class CMFCtext4View : public CView
{
protected: // �������л�����
	CMFCtext4View();
	DECLARE_DYNCREATE(CMFCtext4View)

// ����
public:
	CMFCtext4Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCtext4View();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCtext4View.cpp �еĵ��԰汾
inline CMFCtext4Doc* CMFCtext4View::GetDocument() const
   { return reinterpret_cast<CMFCtext4Doc*>(m_pDocument); }
#endif

