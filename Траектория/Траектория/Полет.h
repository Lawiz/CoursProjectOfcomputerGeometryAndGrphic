#pragma once
#include "MYGDI.H"
class Полет
{
public:
	double Скорость,Угол,Время;
	CMatrix Точки;
	int ЧислоТочек;
	CRectD МК;

	Полет(void);
	void Сброс();
	void Рисовать(CDC& dc,CRect& ОК);
	void Лететь();

	~Полет(void);
};

