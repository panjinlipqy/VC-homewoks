
// MFCZhongHe2(1)Doc.h : CMFCZhongHe21Doc ��Ľӿ�
//


#pragma once
#include "MFCZhongHe2(1)Set.h"


class CMFCZhongHe21Doc : public CDocument
{
protected: // �������л�����
	CMFCZhongHe21Doc();
	DECLARE_DYNCREATE(CMFCZhongHe21Doc)

// ����
public:
	CMFCZhongHe21Set m_MFCZhongHe21Set;

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
	virtual ~CMFCZhongHe21Doc();
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
