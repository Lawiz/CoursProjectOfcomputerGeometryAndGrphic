#pragma once
#include "afxwin.h"


// ���������� ���� ���������

class Config : public CDialogEx
{
	DECLARE_DYNAMIC(���������)

public:
	Config(CWnd* pParent = NULL);   // ����������� �����������
	virtual ~���������();

// ������ ����������� ����
	enum { IDD = IDD_DIALOG1 };
	double V,fi;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	// ���� ��� ����� ��������
	CEdit ����V;
	// ���� ��� ����� ����
	CEdit �����;
	afx_msg void OnBnClickedOk();
	afx_msg double Speed();
	afx_msg double Angele();
};
