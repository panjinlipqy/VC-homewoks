
// MFCtext6View.h : CMFCtext6View ��Ľӿ�
//

#pragma once


class CMFCtext6View : public CView
{
protected: // �������л�����
	CMFCtext6View();
	DECLARE_DYNCREATE(CMFCtext6View)

// ����
public:
	CMFCtext6Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCtext6View();
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
};

#ifndef _DEBUG  // MFCtext6View.cpp �еĵ��԰汾
inline CMFCtext6Doc* CMFCtext6View::GetDocument() const
   { return reinterpret_cast<CMFCtext6Doc*>(m_pDocument); }
#endif

