
// MFCtext13(2)(2)View.h : CMFCtext1322View ��Ľӿ�
//

#pragma once


class CMFCtext1322View : public CView
{
protected: // �������л�����
	CMFCtext1322View();
	DECLARE_DYNCREATE(CMFCtext1322View)

// ����
public:
	CMFCtext1322Doc* GetDocument() const;

// ����
public:
	int a;
	int b;
	int x;
	int y;
	CRect re;
	int flag;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCtext1322View();
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
	afx_msg void OnPop();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnClor();
};

#ifndef _DEBUG  // MFCtext13(2)(2)View.cpp �еĵ��԰汾
inline CMFCtext1322Doc* CMFCtext1322View::GetDocument() const
   { return reinterpret_cast<CMFCtext1322Doc*>(m_pDocument); }
#endif

