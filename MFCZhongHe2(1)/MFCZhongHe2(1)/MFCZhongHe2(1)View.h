
// MFCZhongHe2(1)View.h : CMFCZhongHe21View ��Ľӿ�
//

#pragma once

class CMFCZhongHe21Set;

class CMFCZhongHe21View : public CRecordView
{
protected: // �������л�����
	CMFCZhongHe21View();
	DECLARE_DYNCREATE(CMFCZhongHe21View)

public:
	enum{ IDD = IDD_MFCZHONGHE21_FORM };
	CMFCZhongHe21Set* m_pSet;

// ����
public:
	CMFCZhongHe21Doc* GetDocument() const;

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
	virtual ~CMFCZhongHe21View();
	void draw(CString file);
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
	afx_msg void OnEnChangeEdit2();
	CString name;
	CString id;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
};

#ifndef _DEBUG  // MFCZhongHe2(1)View.cpp �еĵ��԰汾
inline CMFCZhongHe21Doc* CMFCZhongHe21View::GetDocument() const
   { return reinterpret_cast<CMFCZhongHe21Doc*>(m_pDocument); }
#endif

