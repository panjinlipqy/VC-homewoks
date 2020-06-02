
// MFCZongHe1View.h : CMFCZongHe1View ��Ľӿ�
//

#pragma once

class CMFCZongHe1Set;

class CMFCZongHe1View : public CRecordView
{
protected: // �������л�����
	CMFCZongHe1View();
	DECLARE_DYNCREATE(CMFCZongHe1View)

public:
	enum{ IDD = IDD_MFCZONGHE1_FORM };
	CMFCZongHe1Set* m_pSet;

// ����
public:
	CMFCZongHe1Doc* GetDocument() const;
	void draw(CString file);

// ����
public:
	CString path;

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CMFCZongHe1View();
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
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // MFCZongHe1View.cpp �еĵ��԰汾
inline CMFCZongHe1Doc* CMFCZongHe1View::GetDocument() const
   { return reinterpret_cast<CMFCZongHe1Doc*>(m_pDocument); }
#endif

