#include <iostream>
#include <cmath>
#include <conio.h>

using namespace std;


double f(const double x)
{
     // return (sin(2*x))/(1+x*x);
	  return (log(x));
	  //return sin(x);
}

double f1(const double x)
{
     return (sin(2*x))/(1+x*x);
	 
}


double ff(int i, const double a, const double h, double (*f)(double))
{
    return f(a + h*i/2);
}

double simpson(const double a, const double b, double (*f)(double), const double eps)
{
    double h, s = 0, s_old, s1, s2;
    int i, n=1;

    do {
        h = (b - a) / n;
        s_old = s;

        s1 = 0;
        for (i = 2; i < 2*n-1; i += 2)
            s1 += ff(i, a, h, f);

        s2 = 0;
        for (i = 1; i < 2*n; i += 2)
            s2 += ff(i, a, h, f);

        s = h/6 * (ff(0, a, h, f) + 2*s1 + 4*s2 + ff(2*n, a, h, f));
    } while ((abs(s_old - s) > eps*h*n / (b - a)) && (n *= 2));

    return s;
}

int main()
{
	double a, b, eps; 
	int n;
	a=1;
	b=2;
	eps=0.00001;
    cout<<"Integral f= " << simpson(a, b, f, eps)<<"\t2ln2-1: "<<2*log(2.)-1<<"\n";
	cout<<"Integral f= " << simpson(0, 3, f1, eps);
	getch();
    return 0;
}

