
// MFCtext2(3)View.h : CMFCtext23View ��Ľӿ�
//

#pragma once


class CMFCtext23View : public CView
{
protected: // �������л�����
	CMFCtext23View();
	DECLARE_DYNCREATE(CMFCtext23View)

// ����
public:
	CMFCtext23Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCtext23View();
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
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCtext2(3)View.cpp �еĵ��԰汾
inline CMFCtext23Doc* CMFCtext23View::GetDocument() const
   { return reinterpret_cast<CMFCtext23Doc*>(m_pDocument); }
#endif

