
// MFCZhongHe3View.h : CMFCZhongHe3View ��Ľӿ�
//

#pragma once

class CMFCZhongHe3Set;

class CMFCZhongHe3View : public CRecordView
{
protected: // �������л�����
	CMFCZhongHe3View();
	DECLARE_DYNCREATE(CMFCZhongHe3View)

public:
	enum{ IDD = IDD_MFCZHONGHE3_FORM };
	CMFCZhongHe3Set* m_pSet;

// ����
public:
	CMFCZhongHe3Doc* GetDocument() const;

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
	virtual ~CMFCZhongHe3View();
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
	CString text;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};

#ifndef _DEBUG  // MFCZhongHe3View.cpp �еĵ��԰汾
inline CMFCZhongHe3Doc* CMFCZhongHe3View::GetDocument() const
   { return reinterpret_cast<CMFCZhongHe3Doc*>(m_pDocument); }
#endif

