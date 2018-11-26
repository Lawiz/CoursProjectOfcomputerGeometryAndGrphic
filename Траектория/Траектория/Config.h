#pragma once
#include "afxwin.h"


// диалоговое окно Настройки

class Config : public CDialogEx
{
	DECLARE_DYNAMIC(Настройки)

public:
	Config(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~Настройки();

// Данные диалогового окна
	enum { IDD = IDD_DIALOG1 };
	double V,fi;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	// поле для ввода скорости
	CEdit ПолеV;
	// поле для ввода угла
	CEdit ПолеФ;
	afx_msg void OnBnClickedOk();
	afx_msg double Speed();
	afx_msg double Angele();
};
