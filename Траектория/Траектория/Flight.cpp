#include "StdAfx.h"
#include "�����.h"


�����::�����(void)
{
	�����=0;
	Speed=100;
	Angele=60;
	����������=1;
	�����.RedimMatrix(3,1024);
	�����(0,0)=0;
	�����(1,0)=0;
	�����(2,0)=1;
	��.SetRectD(0,0,1000,500);
}
void �����::Reset(){
	�����=0;
	����������=1;
}
void �����::��������(CDC& dc,CRect& ��){
	//������ ������ ����� � ������ ���
	CPen* pp=new CPen(PS_SOLID,2,RGB(0,0,0));
	dc.SelectObject(pp);
	dc.MoveTo(��.left-10,��.top+30);
	dc.LineTo(��.left,��.top+10);
	dc.LineTo(��.left+10,��.top+30);
	dc.MoveTo(��.left,��.top+10);
	dc.LineTo(��.left,��.bottom);
	dc.LineTo(��.right-10,��.bottom);
	dc.LineTo(��.right-30,��.bottom-10);
	dc.MoveTo(��.right-10,��.bottom);
	dc.LineTo(��.right-30,��.bottom+10);
	//������ ����������
	pp=new CPen(PS_DOT,1,RGB(64,64,255));
	dc.SelectObject(pp);
	CMatrix K=SpaceToWindow(��,��);
	CMatrix W(3);
	CPoint p;
	W=K*�����.GetCol(0);
	p.x=W(0);
	p.y=W(1);
	dc.MoveTo(p);
	for(int i=1;i<����������;i++){
		W=K*�����.GetCol(i);
		p.x=W(0);
		p.y=W(1);
		dc.LineTo(p);
	}

	
	//������ ����
	pp=new CPen(PS_SOLID,1,RGB(0,0,128));
	CBrush* br=new CBrush(RGB(64,64,255));
	dc.SelectObject(br);
	dc.SelectObject(pp);
	dc.Ellipse(p.x-5,p.y-5,p.x+5,p.y+5);
	//������ ����������� ��������
	W(0)=Speed*cos(Angele*pi/180)*(�����+1);
	W(1)=Speed*sin(Angele*pi/180)*(�����+1)-5*(�����+1)*(�����+1);
	W=K*W;
	p.x=W(0);
	p.y=W(1);
		dc.LineTo(p);
		delete pp;
		delete br;
}
void �����::������(){
	�����+=0.2;
	�����(0,����������)=Speed*cos(Angele*pi/180)*�����;
	�����(1,����������)=Speed*sin(Angele*pi/180)*�����-5*�����*�����;
	�����(2,����������)=1;
	����������++;
}

�����::~�����(void)
{
}
