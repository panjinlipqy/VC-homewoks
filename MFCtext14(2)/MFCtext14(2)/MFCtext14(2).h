
// MFCtext14(2).h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCtext142App:
// �йش����ʵ�֣������ MFCtext14(2).cpp
//

class CMFCtext142App : public CWinApp
{
public:
	CMFCtext142App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCtext142App theApp;