
// MFCtext1(3)View.h : CMFCtext13View ��Ľӿ�
//

#pragma once


class CMFCtext13View : public CView
{
protected: // �������л�����
	CMFCtext13View();
	DECLARE_DYNCREATE(CMFCtext13View)

// ����
public:
	CMFCtext13Doc* GetDocument() const;

// ����
public:
	CRect cr;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCtext13View();
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

#ifndef _DEBUG  // MFCtext1(3)View.cpp �еĵ��԰汾
inline CMFCtext13Doc* CMFCtext13View::GetDocument() const
   { return reinterpret_cast<CMFCtext13Doc*>(m_pDocument); }
#endif

