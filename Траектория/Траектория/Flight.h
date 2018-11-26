#pragma once
#include "MYGDI.H"
class Flight
{
public:
	double Speed,Angele,Время;
	CMatrix Points;
	int PointsCount;
	CRectD МК;

	Полет(void);
	void Reset();
	void Drow(CDC& dc,CRect& ОК);
	void Flight();

	~Fly(void);
};

