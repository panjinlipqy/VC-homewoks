
// MFCtext2(1)View.h : CMFCtext21View ��Ľӿ�
//

#pragma once


class CMFCtext21View : public CView
{
protected: // �������л�����
	CMFCtext21View();
	DECLARE_DYNCREATE(CMFCtext21View)

// ����
public:
	CMFCtext21Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCtext21View();
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

#ifndef _DEBUG  // MFCtext2(1)View.cpp �еĵ��԰汾
inline CMFCtext21Doc* CMFCtext21View::GetDocument() const
   { return reinterpret_cast<CMFCtext21Doc*>(m_pDocument); }
#endif

