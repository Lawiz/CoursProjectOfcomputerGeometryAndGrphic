// Настройки.cpp: файл реализации
//

#include "stdafx.h"
#include "Траектория.h"
#include "Настройки.h"
#include "afxdialogex.h"


// диалоговое окно Настройки

IMPLEMENT_DYNAMIC(Настройки, CDialogEx)

Настройки::Настройки(CWnd* pParent /*=NULL*/)
	: CDialogEx(Настройки::IDD, pParent)
{

}

Настройки::~Настройки()
{
}

void Настройки::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, ПолеV);
	DDX_Control(pDX, IDC_EDIT2, ПолеФ);
}


BEGIN_MESSAGE_MAP(Настройки, CDialogEx)
	ON_BN_CLICKED(IDOK, &Настройки::OnBnClickedOk)
END_MESSAGE_MAP()


// обработчики сообщений Настройки


void Настройки::OnBnClickedOk()
{
	char* str=new char[25];
	ПолеV.GetWindowTextA(str,25);
	V=atof(str);
	ПолеФ.GetWindowTextA(str,25);
	fi=atof(str);
	CDialogEx::OnOK();
}
double Настройки::Speed(){
	return V;
}
double Настройки::Angele(){
	return fi;
}