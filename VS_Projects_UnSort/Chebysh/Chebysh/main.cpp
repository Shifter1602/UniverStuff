#include <iostream>
#include <conio.h>
#include <math.h>
#include <cstring>
using namespace std;

double Lagrang (const double *x, const double *y, const int n, double z)
{
	double sum=0, pr;
	for (int i=0; i<n; i++)
	{
		pr=1;
		for (int k=0; k<n; k++)
		{
			if (k!=i)
			{
				pr*=((z-x[k])/(x[i]-x[k]));
			}
		}
		sum+=pr*y[i];
	}
	return sum;
}

double Chebyshev(const int n, const double x)
{
	double T0=1; T1=x; T2=1;
	for(int i=0; i<n; i++)
	{
		T2=2*x*T1-T0;
		T0=T1;
		T1=T2;
		return T2;
	}

}


void main()
{
	/*double x[]={0,1,3};
	double y[]={0,1,27};
	cout<<Lagrang(x,y,3,1.5)<<endl;
	
	double x[]={(6-sqrt(18.0f))/4,3/2,(6+sqrt(18.0f))/4};
	double y[]={x[0]^3,x[1]^3,x[2]^3};
	cout<<Lagrang(x,y,3,1.5)<<endl;*/

	cout<<Chebyshev(0, 0);
	_getch();
}
