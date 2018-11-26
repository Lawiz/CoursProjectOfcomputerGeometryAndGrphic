
// Траектория.h : главный файл заголовка для приложения Траектория
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CТраекторияApp:
// О реализации данного класса см. Траектория.cpp
//

class CТраекторияApp : public CWinApp
{
public:
	CТраекторияApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CТраекторияApp theApp;
