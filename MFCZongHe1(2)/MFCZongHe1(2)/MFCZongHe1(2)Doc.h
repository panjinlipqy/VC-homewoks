
// MFCZongHe1(2)Doc.h : CMFCZongHe12Doc ��Ľӿ�
//


#pragma once
#include "MFCZongHe1(2)Set.h"


class CMFCZongHe12Doc : public CDocument
{
protected: // �������л�����
	CMFCZongHe12Doc();
	DECLARE_DYNCREATE(CMFCZongHe12Doc)

// ����
public:
	CMFCZongHe12Set m_MFCZongHe12Set;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMFCZongHe12Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
