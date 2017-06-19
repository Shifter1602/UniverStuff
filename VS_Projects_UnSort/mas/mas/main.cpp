#include <iostream>
#include <stdio.h>
#include <math.h>
#include <conio.h>
using namespace std;

int main()
{
	int maximum, summa=0;
	int massive[]={1, 2, 3, 4, 6, -6 , 5, -4, -7, -8, 3, 2, -9, -9};
	maximum = massive[0];
	for( int i=1; i<14; i++)
		if(maximum<massive[i]) 
			maximum = massive[i];
	cout<<maximum;

	bool nashel=false;
	for(int i=13; i>=0; i--)
		if(nashel)
			summa+=massive[i];
		else if(massive[i]>0)
		{
			nashel=true;
			summa+=massive[i];
		}
	cout<<"\n"<<summa<<endl;

	int a, b;
	cin>>a>>b;
	for(int i=0;i<14;i++)
		if(abs(massive[i])>=a  && abs(massive[i])<=b)
			massive[i]=0;

	for(int i=0;i<14;i++)
		cout<<massive[i]<<"; ";

	for(int i=13; i>=0; i--)
		if(massive[i]!=0)
			for(int j=i-1; j>=0;j--)
				if(massive[j]==0)
				{
					massive[j]=massive[i];
					massive[i]=0;
				}

	cout<<endl;				
	for(int i=0;i<14;i++)
		cout<<massive[i]<<"; ";

	getch();
	return 0;
}