
// ChildView.h : ��������� ������ CChildView
//


#pragma once
#include "�����.h"
// ���� CChildView

class CChildView : public CWnd
{
// ��������
public:
	CChildView();

// ��������
public:
	����� �;
	double V,fi;
	CRect ��;
	bool ��������;
// ��������
public:

// ���������������
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ����������
public:
	virtual ~CChildView();

	// ��������� ������� ����� ���������
protected:
	afx_msg void OnPaint();
	afx_msg void OnKeyDown(UINT nChar,UINT nRepCount,UINT nFlags);
	afx_msg void OnTimer(UINT flag);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32771();
	afx_msg void On32772();
};

