
// MFCtext4(3)View.h : CMFCtext43View ��Ľӿ�
//

#pragma once


class CMFCtext43View : public CView
{
protected: // �������л�����
	CMFCtext43View();
	DECLARE_DYNCREATE(CMFCtext43View)

// ����
public:
	CMFCtext43Doc* GetDocument() const;

// ����
public:
	int a,b,c,count;
	CString s1, s2, s3, s4, f1, f2, f3, f4;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCtext43View();
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

#ifndef _DEBUG  // MFCtext4(3)View.cpp �еĵ��԰汾
inline CMFCtext43Doc* CMFCtext43View::GetDocument() const
   { return reinterpret_cast<CMFCtext43Doc*>(m_pDocument); }
#endif

