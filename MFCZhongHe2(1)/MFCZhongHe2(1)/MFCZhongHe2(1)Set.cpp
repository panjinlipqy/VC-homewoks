
// MFCZhongHe2(1)Set.cpp : CMFCZhongHe21Set ���ʵ��
//

#include "stdafx.h"
#include "MFCZhongHe2(1).h"
#include "MFCZhongHe2(1)Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCZhongHe21Set ʵ��

// ���������� 2020��6��8��, 8:43

IMPLEMENT_DYNAMIC(CMFCZhongHe21Set, CRecordset)

CMFCZhongHe21Set::CMFCZhongHe21Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	column1 = L"";
	column2 = L"";
	column3 = L"";
	m_nFields = 4;
	m_nDefaultType = snapshot;
}
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMFCZhongHe21Set::GetDefaultConnect()
{
	return _T("DSN\x7efc\x5408\x76f8\x7247;DBQ=C:\\vc\x4ee3\x7801\x6682\x5b58\\Database3.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFCZhongHe21Set::GetDefaultSQL()
{
	return _T("[ѧ��������Ϣ������Ƭ��]");
}

void CMFCZhongHe21Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[����]"), column1);
	RFX_Text(pFX, _T("[ѧ��]"), column2);
	RFX_Text(pFX, _T("[��Ƭ]"), column3);

}
/////////////////////////////////////////////////////////////////////////////
// CMFCZhongHe21Set ���

#ifdef _DEBUG
void CMFCZhongHe21Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFCZhongHe21Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

