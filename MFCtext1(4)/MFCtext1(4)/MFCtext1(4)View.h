
// MFCtext1(4)View.h : CMFCtext14View ��Ľӿ�
//

#pragma once


class CMFCtext14View : public CView
{
protected: // �������л�����
	CMFCtext14View();
	DECLARE_DYNCREATE(CMFCtext14View)

// ����
public:
	CMFCtext14Doc* GetDocument() const;

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
	virtual ~CMFCtext14View();
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

#ifndef _DEBUG  // MFCtext1(4)View.cpp �еĵ��԰汾
inline CMFCtext14Doc* CMFCtext14View::GetDocument() const
   { return reinterpret_cast<CMFCtext14Doc*>(m_pDocument); }
#endif

