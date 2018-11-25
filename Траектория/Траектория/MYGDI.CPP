//вспомагательные функции
#pragma once
#include "stdafx.h"
#include "MyGDI.h"
//преобразование координат из ВСК в ОСК
CMatrix SpaceToWindow(CRectD& МК, CRect& ОК){
	CMatrix m(3,3);
	double kx=(ОК.right-ОК.left)/(МК.right-МК.left);
	double ky=(ОК.bottom-ОК.top)/(МК.top-МК.bottom);
	m(2,2)=1;
	m(0,0)=kx;
	m(1,1)=ky;
	m(0,2)=ОК.left-kx*МК.left;
	m(1,2)=ОК.top-ky*МК.bottom;
	return m;
}
