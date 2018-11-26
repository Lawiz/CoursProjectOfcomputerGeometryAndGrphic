
// ChildView.h : интерфейс класса CChildView
//


#pragma once
#include "Flight.h"
// окно CChildView

class CChildView : public CWnd
{
// Creating
public:
	CChildView();

// Attrs
public:
	Flight Flight;
	double V,fi;
	CRect ОК;
	bool Anemation;
// Operation
public:

// Oweride
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implimentation
public:
	virtual ~CChildView();

	// Create function for shemes of messages
protected:
	afx_msg void OnPaint();
	afx_msg void OnKeyDown(UINT nChar,UINT nRepCount,UINT nFlags);
	afx_msg void OnTimer(UINT flag);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32771();
	afx_msg void On32772();
};

