
// MFCtext4(2)Doc.h : CMFCtext42Doc ��Ľӿ�
//


#pragma once


class CMFCtext42Doc : public CDocument
{
protected: // �������л�����
	CMFCtext42Doc();
	DECLARE_DYNCREATE(CMFCtext42Doc)

// ����
public:

// ����
public:
	int A;
	int B;
	int sum;
	CString s;
	CString s2;
	CString s3;

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
	virtual ~CMFCtext42Doc();
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
