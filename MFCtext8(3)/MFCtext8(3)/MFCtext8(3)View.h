
// MFCtext8(3)View.h : CMFCtext83View ��Ľӿ�
//

#pragma once


class CMFCtext83View : public CView
{
protected: // �������л�����
	CMFCtext83View();
	DECLARE_DYNCREATE(CMFCtext83View)

// ����
public:
	CMFCtext83Doc* GetDocument() const;

// ����
public:
	CPoint sp, ep;
	bool set;
	int flag;
	CRect r;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCtext83View();
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
	afx_msg void Onshowline();
	afx_msg void Onshowrect();
	afx_msg void Onshowelispse();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCtext8(3)View.cpp �еĵ��԰汾
inline CMFCtext83Doc* CMFCtext83View::GetDocument() const
   { return reinterpret_cast<CMFCtext83Doc*>(m_pDocument); }
#endif

