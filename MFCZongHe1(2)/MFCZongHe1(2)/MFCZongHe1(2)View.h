
// MFCZongHe1(2)View.h : CMFCZongHe12View ��Ľӿ�
//

#pragma once

class CMFCZongHe12Set;

class CMFCZongHe12View : public CRecordView
{
protected: // �������л�����
	CMFCZongHe12View();
	DECLARE_DYNCREATE(CMFCZongHe12View)

public:
	enum{ IDD = IDD_MFCZONGHE12_FORM };
	CMFCZongHe12Set* m_pSet;

// ����
public:
	CMFCZongHe12Doc* GetDocument() const;
	void draw(CString file);

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CMFCZongHe12View();
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
	CString name;
	CString id;
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
};

#ifndef _DEBUG  // MFCZongHe1(2)View.cpp �еĵ��԰汾
inline CMFCZongHe12Doc* CMFCZongHe12View::GetDocument() const
   { return reinterpret_cast<CMFCZongHe12Doc*>(m_pDocument); }
#endif

