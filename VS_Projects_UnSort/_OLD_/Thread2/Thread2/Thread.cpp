#include "stdafx.h"
#include <complex>
#include "Thread.h"
using namespace std;
CEvent gExit;
UINT Fractal(LPVOID hWnd)
{
	CClientDC dc((CWnd*)hWnd);//объ€вл. контекст устройства дл€ окна в кот. будет выполн. рисование, выполнив €вн. преобр. типа дл€ указ. на это окно
	RECT rect;
	((CWnd*)hWnd)->GetClientRect(&rect);//¬ычисл€ем и запоминаем размеры окна представлени€
	complex<double> c(-0.012, 0.74);// онстанта комплексного числа
	for(int i=rect.left; i<=rect.right; i++)
		for(int j=rect.top; j<=rect.bottom; j++)
		{
			if (WaitForSingleObject(gExit,0)==WAIT_OBJECT_0) return 1;//при по€вл. синхр. событи€ досрочно прерыв. поток
			complex<double> x(0.0001*i, 0.0001*j);
			for(int n=0; n<100; n++)
			{
				if(abs(x)>100)
					break;
				else
					x=pow(x,2)+c;
				if(abs(x)<1)
					dc.SetPixel(i, j, RGB(0, 0, 255));
				else
					dc.SetPixel(i, j, RGB(2*abs(x), 255, 255));
			}
		}
}