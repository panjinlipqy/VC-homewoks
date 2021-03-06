
// MFCZhongHe2(1)Set.cpp : CMFCZhongHe21Set 类的实现
//

#include "stdafx.h"
#include "MFCZhongHe2(1).h"
#include "MFCZhongHe2(1)Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCZhongHe21Set 实现

// 代码生成在 2020年6月8日, 8:43

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
//#error 安全问题：连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CMFCZhongHe21Set::GetDefaultConnect()
{
	return _T("DSN\x7efc\x5408\x76f8\x7247;DBQ=C:\\vc\x4ee3\x7801\x6682\x5b58\\Database3.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFCZhongHe21Set::GetDefaultSQL()
{
	return _T("[学生基本信息（含相片）]");
}

void CMFCZhongHe21Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[姓名]"), column1);
	RFX_Text(pFX, _T("[学号]"), column2);
	RFX_Text(pFX, _T("[相片]"), column3);

}
/////////////////////////////////////////////////////////////////////////////
// CMFCZhongHe21Set 诊断

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

