
// MFCtext14(1)View.h : CMFCtext141View ��Ľӿ�
//

#pragma once


class CMFCtext141View : public CView
{
protected: // �������л�����
	CMFCtext141View();
	DECLARE_DYNCREATE(CMFCtext141View)

// ����
public:
	CMFCtext141Doc* GetDocument() const;

// ����
public:
	CString filename;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCtext141View();
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
	afx_msg void OnFileSaveAs();
};

#ifndef _DEBUG  // MFCtext14(1)View.cpp �еĵ��԰汾
inline CMFCtext141Doc* CMFCtext141View::GetDocument() const
   { return reinterpret_cast<CMFCtext141Doc*>(m_pDocument); }
#endif

