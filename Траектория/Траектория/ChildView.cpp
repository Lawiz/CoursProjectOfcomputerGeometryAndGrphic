
// ChildView.cpp : ���������� ������ CChildView
//

#include "stdafx.h"
#include "����������.h"
#include "ChildView.h"
#include "���������.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	��.SetRect(20,20,1020,520);
	��������=false;
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



// ����������� ��������� CChildView

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
	CPaintDC dc(this); // �������� ���������� ��� ���������

	�.��������(dc,��);
}

void CChildView::OnKeyDown(UINT nChar,UINT nRepCount,UINT nFlags){
	if(nChar==32){ //����������
		if(��������){
			KillTimer(1);
			��������=false;
		}
		else{
			�.�����();
			�.��������=V;
			�.����=fi;
			SetTimer(1,30,NULL);
			��������=true;
		}

	}
	Invalidate();
}

void CChildView::OnTimer(UINT flag){
	if(��������){
		if(�.�����(1,�.����������-1)<=0 && �.����������>1){
			�.����������--;
			��������=false;
			KillTimer(1);
		}
		else{
			�.������();
		}
		Invalidate();
	}
}

void CChildView::On32771()
{
	��������� �����;
	if(�����.DoModal()==IDOK){
		V=�����.��������();
		fi=�����.����();
		�.��������=V;
		�.����=fi;
		Invalidate();
	}
}


void CChildView::On32772()
{
	�.�����();
	�.��������=V;
	�.����=fi;
	SetTimer(1,30,NULL);
	��������=true;
}
