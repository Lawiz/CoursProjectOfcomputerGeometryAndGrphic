//��������������� �������
#pragma once
#include "stdafx.h"
#include "MyGDI.h"
//�������������� ��������� �� ��� � ���
CMatrix SpaceToWindow(CRectD& ��, CRect& ��){
	CMatrix m(3,3);
	double kx=(��.right-��.left)/(��.right-��.left);
	double ky=(��.bottom-��.top)/(��.top-��.bottom);
	m(2,2)=1;
	m(0,0)=kx;
	m(1,1)=ky;
	m(0,2)=��.left-kx*��.left;
	m(1,2)=��.top-ky*��.bottom;
	return m;
}
