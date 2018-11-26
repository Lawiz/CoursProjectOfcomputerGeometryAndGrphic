
// ChildView.cpp : реализация класса CChildView
//

#include "stdafx.h"
#include "Trajectory.h"
#include "ChildView.h"
#include "Config.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	ОК.SetRect(20,20,1020,520);
	Anemation=false;
	V=100;
	fi=60;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_TIMER()	
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_32771, &CChildView::On32771)
	ON_COMMAND(ID_32771, &CChildView::On32771)
	ON_COMMAND(ID_32772, &CChildView::On32772)
END_MESSAGE_MAP()



// обработчики сообщений CChildView

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // контекст устройства для рисования

	П.Рисовать(dc,ОК);
}

void CChildView::OnKeyDown(UINT nChar,UINT nRepCount,UINT nFlags){
	if(nChar==32){ //перезапуск
		if(Anemation){
			KillTimer(1);
			Anemation=false;
		}
		else{
			Flight.Reset();
			Flight.Speed=V;
			Flight.Angele=fi;
			SetTimer(1,30,NULL);
			Anemation=true;
		}

	}
	Invalidate();
}

void CChildView::OnTimer(UINT flag){
	if(Anemation){
		if(Flight.Points(1,П.ЧислоТочек-1)<=0 && П.ЧислоТочек>1){
			Flight.PointsCount--;
			Anemation=false;
			KillTimer(1);
		}
		else{
			Flight.Fly();
		}
		Invalidate();
	}
}

void CChildView::On32771()
{
	Настройки Настр;
	if(Настр.DoModal()==IDOK){
		V=Настр.Speed();
		fi=Настр.Angele();
		П.Speed=V;
		П.Angele=fi;
		Invalidate();
	}
}


void CChildView::On32772()
{
	П.Reset();
	П.Speed=V;
	П.Angele=fi;
	SetTimer(1,30,NULL);
	Anemation=true;
}
