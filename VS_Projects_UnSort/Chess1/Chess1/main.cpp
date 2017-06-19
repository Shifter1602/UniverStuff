#include <iostream>
#include <algorithm>
using namespace std;

int desk[8][8]=
{
	4,2,3,6,5,3,2,4,
	1,1,1,1,1,1,1,1,
	0,0,-1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	-1,-1,-1,-1,-1,-1,-1,-1,
	-4,-2,-3,-6,-5,-3,-2,-4
};
void show()
{
	for(int i=0;i<8;i++)
	{
		cout<<"\n";
		for(int j=0;j<8;j++)
		cout<<desk[i][j]<<"\t";
	}
}

void Swap(int a,int b)
{
	int c;
	c=a;a=b;b=c;
}

int main()
{
int a,b,c,d;
char sw;
show();
for(;;)
{
cin>>sw;
switch(sw)
{
case '1':
	{
		cout<<"\n"<<"Input source\n";
		cin>>a>>b;
		cout<<"\n"<<"Input destination\n";
		cin>>c>>d;
		cout<<desk[a][b];
		cout<<desk[c][d];
		if(desk[a][b]==1)
		{
			if(desk[a+1][b]==0 &&  a+1==c && b==d) {desk[c][d]=desk[a][b];desk[a][b]=0;}
			if(a==1 && desk[a+1][b]==0 && desk[a+2][b]==0 && a+2==c && b==d) {desk[c][d]=desk[a][b];desk[a][b]=0;}
			if(desk[a+1][b+1]<0 && a+1==c && b+1==d){desk[c][d]=desk[a][b];desk[a][b]=0;}
			if(desk[a+1][b-1]<0 && a+1==c && b-1==d){desk[c][d]=desk[a][b];desk[a][b]=0;}
		}
		

	}
	break;
case '2':
	show();
	break;

case '-1': return 0;
	break;
}
}













}

