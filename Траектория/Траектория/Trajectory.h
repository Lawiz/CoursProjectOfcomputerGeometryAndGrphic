
// ����������.h : ������� ���� ��������� ��� ���������� ����������
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// C����������App:
// � ���������� ������� ������ ��. ����������.cpp
//

class C����������App : public CWinApp
{
public:
	C����������App();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C����������App theApp;
