
// MFCtext2(2)View.h : CMFCtext22View ��Ľӿ�
//

#pragma once


class CMFCtext22View : public CView
{
protected: // �������л�����
	CMFCtext22View();
	DECLARE_DYNCREATE(CMFCtext22View)

// ����
public:
	CMFCtext22Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCtext22View();
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

#ifndef _DEBUG  // MFCtext2(2)View.cpp �еĵ��԰汾
inline CMFCtext22Doc* CMFCtext22View::GetDocument() const
   { return reinterpret_cast<CMFCtext22Doc*>(m_pDocument); }
#endif

