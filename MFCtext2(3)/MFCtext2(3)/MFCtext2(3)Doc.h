
// MFCtext2(3)Doc.h : CMFCtext23Doc ��Ľӿ�
//


#pragma once


class CMFCtext23Doc : public CDocument
{
protected: // �������л�����
	CMFCtext23Doc();
	DECLARE_DYNCREATE(CMFCtext23Doc)

// ����
public:
	int count; //(3)
	CString s3;
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
	virtual ~CMFCtext23Doc();
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
