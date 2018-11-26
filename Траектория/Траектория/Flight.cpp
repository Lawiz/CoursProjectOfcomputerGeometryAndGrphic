#include "StdAfx.h"
#include "Полет.h"


Полет::Полет(void)
{
	Время=0;
	Speed=100;
	Angele=60;
	ЧислоТочек=1;
	Точки.RedimMatrix(3,1024);
	Точки(0,0)=0;
	Точки(1,0)=0;
	Точки(2,0)=1;
	МК.SetRectD(0,0,1000,500);
}
void Полет::Reset(){
	Время=0;
	ЧислоТочек=1;
}
void Полет::Рисовать(CDC& dc,CRect& ОК){
	//делаем жирную линию и рисуем оси
	CPen* pp=new CPen(PS_SOLID,2,RGB(0,0,0));
	dc.SelectObject(pp);
	dc.MoveTo(ОК.left-10,ОК.top+30);
	dc.LineTo(ОК.left,ОК.top+10);
	dc.LineTo(ОК.left+10,ОК.top+30);
	dc.MoveTo(ОК.left,ОК.top+10);
	dc.LineTo(ОК.left,ОК.bottom);
	dc.LineTo(ОК.right-10,ОК.bottom);
	dc.LineTo(ОК.right-30,ОК.bottom-10);
	dc.MoveTo(ОК.right-10,ОК.bottom);
	dc.LineTo(ОК.right-30,ОК.bottom+10);
	//рисуем траекторию
	pp=new CPen(PS_DOT,1,RGB(64,64,255));
	dc.SelectObject(pp);
	CMatrix K=SpaceToWindow(МК,ОК);
	CMatrix W(3);
	CPoint p;
	W=K*Точки.GetCol(0);
	p.x=W(0);
	p.y=W(1);
	dc.MoveTo(p);
	for(int i=1;i<ЧислоТочек;i++){
		W=K*Точки.GetCol(i);
		p.x=W(0);
		p.y=W(1);
		dc.LineTo(p);
	}

	
	//рисуем круг
	pp=new CPen(PS_SOLID,1,RGB(0,0,128));
	CBrush* br=new CBrush(RGB(64,64,255));
	dc.SelectObject(br);
	dc.SelectObject(pp);
	dc.Ellipse(p.x-5,p.y-5,p.x+5,p.y+5);
	//рисуем направление движения
	W(0)=Speed*cos(Angele*pi/180)*(Время+1);
	W(1)=Speed*sin(Angele*pi/180)*(Время+1)-5*(Время+1)*(Время+1);
	W=K*W;
	p.x=W(0);
	p.y=W(1);
		dc.LineTo(p);
		delete pp;
		delete br;
}
void Полет::Лететь(){
	Время+=0.2;
	Точки(0,ЧислоТочек)=Speed*cos(Angele*pi/180)*Время;
	Точки(1,ЧислоТочек)=Speed*sin(Angele*pi/180)*Время-5*Время*Время;
	Точки(2,ЧислоТочек)=1;
	ЧислоТочек++;
}

Полет::~Полет(void)
{
}
