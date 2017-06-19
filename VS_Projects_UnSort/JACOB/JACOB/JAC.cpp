#include <iostream>
#include <conio.h>
#include <math.h>


using namespace std;

void Jacobi(const int N, double *A, double *F, double *X, const double eps)
{
	double *TempX = new double[N];
	double norm;
	do{
		for (int i=0; i<N; i++){
			TempX[i]=F[i];
			for (int g=0; g<N; g++){
				if (i!=g)
					TempX[i]-=A[i*N+g]*X[g];
			}
		TempX[i]/=A[i*N+i];
		}

		norm=0;
		for (int h=0; h<N; h++){
			if (fabs(X[h]-TempX[h])>norm)
				norm=fabs(X[h]-TempX[h]);
			X[h] = TempX[h];
		}
	}while (norm>eps);
	delete[] TempX;
			
}


	int main()
	{
		const int count=3;
		double A[]={8,1,-4,2,-6,1,-1,1,4};
		double b[]={6,-9,5};
		double x[]={0,0,0};
		double Eps=0.0001;
		Jacobi(count,A,b,x,Eps);
		for (int i=0; i<count; i++)
			cout<<"\nx("<<i+1<<")="<<floor(x[i]+0.5)<<"\n";
	
		getch();
		return 0;
		
	}