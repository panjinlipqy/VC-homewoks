
// MFCtext9(2)View.h : CMFCtext92View ��Ľӿ�
//

#pragma once


class CMFCtext92View : public CView
{
protected: // �������л�����
	CMFCtext92View();
	DECLARE_DYNCREATE(CMFCtext92View)

// ����
public:
	CMFCtext92Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCtext92View();
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
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // MFCtext9(2)View.cpp �еĵ��԰汾
inline CMFCtext92Doc* CMFCtext92View::GetDocument() const
   { return reinterpret_cast<CMFCtext92Doc*>(m_pDocument); }
#endif

