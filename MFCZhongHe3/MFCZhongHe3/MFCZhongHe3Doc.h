
// MFCZhongHe3Doc.h : CMFCZhongHe3Doc ��Ľӿ�
//


#pragma once
#include "MFCZhongHe3Set.h"


class CMFCZhongHe3Doc : public CDocument
{
protected: // �������л�����
	CMFCZhongHe3Doc();
	DECLARE_DYNCREATE(CMFCZhongHe3Doc)

// ����
public:
	CMFCZhongHe3Set m_MFCZhongHe3Set;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMFCZhongHe3Doc();
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
