
// MFCtext8(2)View.h : CMFCtext82View ��Ľӿ�
//

#pragma once


class CMFCtext82View : public CView
{
protected: // �������л�����
	CMFCtext82View();
	DECLARE_DYNCREATE(CMFCtext82View)

// ����
public:
	CMFCtext82Doc* GetDocument() const;

// ����
public:
	CBitmap m_Bitmap;
	int m_nWidth;
	int m_nHeight;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCtext82View();
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
	afx_msg void OnShowImg();
};

#ifndef _DEBUG  // MFCtext8(2)View.cpp �еĵ��԰汾
inline CMFCtext82Doc* CMFCtext82View::GetDocument() const
   { return reinterpret_cast<CMFCtext82Doc*>(m_pDocument); }
#endif

