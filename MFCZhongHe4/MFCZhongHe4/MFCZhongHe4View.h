
// MFCZhongHe4View.h : CMFCZhongHe4View ��Ľӿ�
//

#pragma once

class CMFCZhongHe4Set;

class CMFCZhongHe4View : public CRecordView
{
protected: // �������л�����
	CMFCZhongHe4View();
	DECLARE_DYNCREATE(CMFCZhongHe4View)

public:
	enum{ IDD = IDD_MFCZHONGHE4_FORM };
	CMFCZhongHe4Set* m_pSet;

// ����
public:
	CMFCZhongHe4Doc* GetDocument() const;
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
	virtual ~CMFCZhongHe4View();
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
	CString number;
	CString name;
	CString sex;
	CString mon;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
};

#ifndef _DEBUG  // MFCZhongHe4View.cpp �еĵ��԰汾
inline CMFCZhongHe4Doc* CMFCZhongHe4View::GetDocument() const
   { return reinterpret_cast<CMFCZhongHe4Doc*>(m_pDocument); }
#endif

