#pragma once
#include "MYGDI.H"
class Flight
{
public:
	double Speed,Angele,�����;
	CMatrix Points;
	int PointsCount;
	CRectD ��;

	�����(void);
	void Reset();
	void Drow(CDC& dc,CRect& ��);
	void Flight();

	~Fly(void);
};

