
// MFCZhongHe4Set.cpp : CMFCZhongHe4Set 类的实现
//

#include "stdafx.h"
#include "MFCZhongHe4.h"
#include "MFCZhongHe4Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCZhongHe4Set 实现

// 代码生成在 2020年6月8日, 22:21

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
//#error 安全问题：连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CMFCZhongHe4Set::GetDefaultConnect()
{
	return _T("DSN=\x7efc\x5408\x76f8\x7247;DBQ=C:\\vc\x4ee3\x7801\x6682\x5b58\\zh4.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFCZhongHe4Set::GetDefaultSQL()
{
	return _T("[综合4]");
}

void CMFCZhongHe4Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[学号]"), column1);
	RFX_Text(pFX, _T("[姓名]"), column2);
	RFX_Text(pFX, _T("[性别]"), column3);
	RFX_Text(pFX, _T("[年薪]"), column4);
	RFX_Text(pFX, _T("[相片]"), column5);

}
/////////////////////////////////////////////////////////////////////////////
// CMFCZhongHe4Set 诊断

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

