// ���������.cpp: ���� ����������
//

#include "stdafx.h"
#include "����������.h"
#include "���������.h"
#include "afxdialogex.h"


// ���������� ���� ���������

IMPLEMENT_DYNAMIC(���������, CDialogEx)

���������::���������(CWnd* pParent /*=NULL*/)
	: CDialogEx(���������::IDD, pParent)
{

}

���������::~���������()
{
}

void ���������::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, ����V);
	DDX_Control(pDX, IDC_EDIT2, �����);
}


BEGIN_MESSAGE_MAP(���������, CDialogEx)
	ON_BN_CLICKED(IDOK, &���������::OnBnClickedOk)
END_MESSAGE_MAP()


// ����������� ��������� ���������


void ���������::OnBnClickedOk()
{
	char* str=new char[25];
	����V.GetWindowTextA(str,25);
	V=atof(str);
	�����.GetWindowTextA(str,25);
	fi=atof(str);
	CDialogEx::OnOK();
}
double ���������::��������(){
	return V;
}
double ���������::����(){
	return fi;
}