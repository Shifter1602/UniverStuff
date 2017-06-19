#include <iostream>
#include <conio.h>
#include <cmath>
#include <cstring>
using namespace std;



double f(double x,double y)
{

	return (y-2)/x+1;
}

int main()
{
	double a=1, b=3, eps=1e-5,h=0.1;//a=x0

	const int  n=10000;
	h=(b-a)/n;
	double X[n];
	double Y[n];
	X[0]=a;
	Y[0]=a*log(a)+2;
	for(int i=0;i<n;i++)
	{
		X[i]=a+i*h;
		Y[i+1]=Y[i]+h*f(X[i],Y[i]);
	}
	
		cout << X[n]<< "  " << Y[n] << " " << 3*log(3.0)+2  << endl;
	
	getch();

}