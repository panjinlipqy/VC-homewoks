
// MFCtext9(1)View.h : CMFCtext91View ��Ľӿ�
//

#pragma once


class CMFCtext91View : public CView
{
protected: // �������л�����
	CMFCtext91View();
	DECLARE_DYNCREATE(CMFCtext91View)

// ����
public:
	CMFCtext91Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFCtext91View();
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

#ifndef _DEBUG  // MFCtext9(1)View.cpp �еĵ��԰汾
inline CMFCtext91Doc* CMFCtext91View::GetDocument() const
   { return reinterpret_cast<CMFCtext91Doc*>(m_pDocument); }
#endif

