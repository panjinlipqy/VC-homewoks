
// MFCZongHe1(2)Set.cpp : CMFCZongHe12Set ���ʵ��
//

#include "stdafx.h"
#include "MFCZongHe1(2).h"
#include "MFCZongHe1(2)Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCZongHe12Set ʵ��

// ���������� 2020��5��30��, 9:30

IMPLEMENT_DYNAMIC(CMFCZongHe12Set, CRecordset)

CMFCZongHe12Set::CMFCZongHe12Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = L"";
	m_2 = L"";
	m_3 = L"";
	m_nFields = 4;
	m_nDefaultType = snapshot;
}
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMFCZongHe12Set::GetDefaultConnect()
{
	return _T("DSN=\x7efc\x5408\x76f8\x7247;DBQ=C:\\vc\x4ee3\x7801\x6682\x5b58\\Database3.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFCZongHe12Set::GetDefaultSQL()
{
	return _T("[ѧ��������Ϣ������Ƭ��]");
}

void CMFCZongHe12Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[�ֶ�1]"), m_1);
	RFX_Text(pFX, _T("[�ֶ�2]"), m_2);
	RFX_Text(pFX, _T("[�ֶ�3]"), m_3);

}
/////////////////////////////////////////////////////////////////////////////
// CMFCZongHe12Set ���

#ifdef _DEBUG
void CMFCZongHe12Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFCZongHe12Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

