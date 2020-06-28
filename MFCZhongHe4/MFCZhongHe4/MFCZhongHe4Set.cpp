
// MFCZhongHe4Set.cpp : CMFCZhongHe4Set ���ʵ��
//

#include "stdafx.h"
#include "MFCZhongHe4.h"
#include "MFCZhongHe4Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCZhongHe4Set ʵ��

// ���������� 2020��6��8��, 22:21

IMPLEMENT_DYNAMIC(CMFCZhongHe4Set, CRecordset)

CMFCZhongHe4Set::CMFCZhongHe4Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	column1 = L"";
	column2 = L"";
	column3 = L"";
	column4 = L"";
	column5 = L"";
	m_nFields = 6;
	m_nDefaultType = dynaset;
}
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMFCZhongHe4Set::GetDefaultConnect()
{
	return _T("DSN=\x7efc\x5408\x76f8\x7247;DBQ=C:\\vc\x4ee3\x7801\x6682\x5b58\\zh4.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFCZhongHe4Set::GetDefaultSQL()
{
	return _T("[�ۺ�4]");
}

void CMFCZhongHe4Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[ѧ��]"), column1);
	RFX_Text(pFX, _T("[����]"), column2);
	RFX_Text(pFX, _T("[�Ա�]"), column3);
	RFX_Text(pFX, _T("[��н]"), column4);
	RFX_Text(pFX, _T("[��Ƭ]"), column5);

}
/////////////////////////////////////////////////////////////////////////////
// CMFCZhongHe4Set ���

#ifdef _DEBUG
void CMFCZhongHe4Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFCZhongHe4Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

