#include <iostream>
#include "Circle_01.h"
#include <conio.h>
using namespace std;

double PI = 3.1415926535897932384626433832795,radius,x,y;

double CCircle::CalcSquare(double radius)
{
	return(PI*radius*radius);
}


CCircle::CCircle()
{
	cout<<"Constructor 1\n";
}

CCircle::CCircle(double radius)
{
	cout<<"Constructor 2\n";
	m_radius = radius;
}


CCircle::~CCircle()
{
	cout << "Destructor\n";
}

void CCircle::SetRadius()
{	
	
	m_radius = radius;
}

void CCircle::GetRadius()
{
	SetRadius();
}




void CCircle::ShowSquare()
{
	cout << "Radius "<< m_radius << "  S=" << CalcSquare(m_radius) << "\n";
}

bool CCircle::InCircle()
{
	if(x*x+y*y<=m_radius*m_radius)
		return 1;
	else return 0;
}

void main()
{
	bool a;
	double score=0;
	cout << "Input radius"<<"\n";
	cin >> radius;
	cout << "Input x"<<"\n";
	cin >> x;
	cout << "Input y"<<"\n";
	cin >> y;
	CCircle cir1;
	cir1.SetRadius();
	cir1.ShowSquare();
	
	CCircle cir2(radius);
	cir2.GetRadius();
	cir2.ShowSquare();	
	//cout<<x<<y<<radius;	
	a=cir1.InCircle();
	cout<<"Popalo? "<<a<<"\n";
	for(int i=0;i<10;i++)
	{
		if(a==0)
			break;
		else
		if((x*x+y*y)<=(radius*radius*(i+1)/10))
		{
			score=10-i;
			break;
		}
		else;
	}
	cout<<"score is "<<score;
	getch();

}