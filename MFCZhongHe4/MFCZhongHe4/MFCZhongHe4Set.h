
// MFCZhongHe4Set.h: CMFCZhongHe4Set ��Ľӿ�
//


#pragma once

// ���������� 2020��6��8��, 22:21

class CMFCZhongHe4Set : public CRecordset
{
public:
	CMFCZhongHe4Set(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CMFCZhongHe4Set)

// �ֶ�/��������

// �����ַ�������(�������)��ӳ���ݿ��ֶ�(ANSI �������͵� CStringA �� Unicode
// �������͵� CStringW)��ʵ���������͡�
//  ����Ϊ��ֹ ODBC ��������ִ�п���
// ����Ҫ��ת�������ϣ�������Խ���Щ��Ա����Ϊ
// CString ���ͣ�ODBC ��������ִ�����б�Ҫ��ת����
// (ע��: ����ʹ�� 3.5 �����߰汾�� ODBC ��������
// ��ͬʱ֧�� Unicode ����Щת��)��

	long	m_ID;
	CStringW	column1;
	CStringW	column2;
	CStringW	column3;
	CStringW	column4;
	CStringW	column5;

// ��д
	// �����ɵ��麯����д
	public:
	virtual CString GetDefaultConnect();	// Ĭ�������ַ���

	virtual CString GetDefaultSQL(); 	// ��¼����Ĭ�� SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ֧��

// ʵ��
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

