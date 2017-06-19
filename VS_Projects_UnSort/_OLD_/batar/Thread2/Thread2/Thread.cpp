
#include "stdafx.h"
#include <complex>
#include "Thread.h"

using namespace std;
CEvent gExit;

UINT Fractal(LPVOID hWnd)
{
	CClientDC dc((CWnd*) hWnd); // объявляем контекст устройства для окна, в котором будет выполняться рисование,
	// выполнив явное преобразование типа для указателя на это окно
	RECT rect;
	((CWnd*) hWnd)->GetClientRect(&rect); // вычисляем и запоминаем размеры окна представления
	complex<double> c(-0.012, 0.74); // константа комплексного числа
	for(int i=rect.left; i<=rect.right; i++)
		for(int j=rect.top; j<=rect.bottom; j++)
		{
			if (WaitForSingleObject(gExit,0)==WAIT_OBJECT_0) // при появлении синхронизирующего события досрочно прервать второй поток
				return 1;
			complex<double> x(0.01*i, 0.0001*j);
			for(int n=0; n<100; n++)
			{
				if(abs(x)>100)
					break;
				else
					x=pow(x,2)+c;
				if(abs(x)<1)
					dc.SetPixel(i, j, RGB(0, 0, 255));
				else
				dc.SetPixel(i, j, RGB(2*abs(x), 128, 128));
			}
}
}