
// MFCZhongHe3Set.cpp : CMFCZhongHe3Set ���ʵ��
//

#include "stdafx.h"
#include "MFCZhongHe3.h"
#include "MFCZhongHe3Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCZhongHe3Set ʵ��

// ���������� 2020��6��8��, 19:26

IMPLEMENT_DYNAMIC(CMFCZhongHe3Set, CRecordset)

CMFCZhongHe3Set::CMFCZhongHe3Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = 0;
	m_nFields = 2;
	m_nDefaultType = dynaset;
}
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMFCZhongHe3Set::GetDefaultConnect()
{
	return _T("DSN=\x7efc\x5408\x76f8\x7247;DBQ=C:\\vc\x4ee3\x7801\x6682\x5b58\\zh3.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFCZhongHe3Set::GetDefaultSQL()
{
	return _T("[�ۺ�3]");
}

void CMFCZhongHe3Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Long(pFX, _T("[�ֶ�1]"), m_1);

}
/////////////////////////////////////////////////////////////////////////////
// CMFCZhongHe3Set ���

#ifdef _DEBUG
void CMFCZhongHe3Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFCZhongHe3Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

