
// MFCtext13��1��.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCtext13��1��App:
// �йش����ʵ�֣������ MFCtext13��1��.cpp
//

class CMFCtext13��1��App : public CWinApp
{
public:
	CMFCtext13��1��App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCtext13��1��App theApp;