
// MFCtext14ʵ��1.h : MFCtext14ʵ��1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCtext14ʵ��1App:
// �йش����ʵ�֣������ MFCtext14ʵ��1.cpp
//

class CMFCtext14ʵ��1App : public CWinAppEx
{
public:
	CMFCtext14ʵ��1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCtext14ʵ��1App theApp;
