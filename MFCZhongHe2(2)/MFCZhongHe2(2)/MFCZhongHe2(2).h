
// MFCZhongHe2(2).h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCZhongHe22App:
// �йش����ʵ�֣������ MFCZhongHe2(2).cpp
//

class CMFCZhongHe22App : public CWinApp
{
public:
	CMFCZhongHe22App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCZhongHe22App theApp;