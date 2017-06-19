#include "cir2.h"
#include <math.h>
#include <iostream>

using namespace std;

CCircle::CCircle()
{
	cout<<"Constructor Default of CCCircle is working...\n";
	m_radius=0;
}
CCircle::CCircle(double radius)
{
	cout<<"Constructor 2 of CCCircle is working...\n";
	m_radius=radius;
}
CCircle::~CCircle()
{
	cout<<"Destructor  CCCircle is working...\n";
}

//======================================================================

CNewCircle::CNewCircle()
{
	cout<<"Constructor Default of CNewCircle is working...\n";
	SetRadius(0);
	
}

CNewCircle::CNewCircle(double radius)
{
	cout<<"Constructor 2 of CNewCircle is working...\n";
	SetRadius(radius);
}


CNewCircle::~CNewCircle()
{
	cout<<"Destructor  CNewCircle is working...\n";
}

double CNewCircle::GetSide1()
{
	return 2*GetRadius() ;
}

double CNewCircle::GetSide2()
{
	return 2*GetRadius()*sqrt(2.0);
}

double CNewCircle::GetLength()
{
	return 2*GetRadius()*3.1415  ;
}

void main()
{
	CNewCircle cir1,cir2(5);
	cir1.SetRadius(10);
	cout<<"Radius ="<<cir1.GetRadius()<<"\nSquare = "<<cir1.GetSquare()<<
		"\nLength = "<<cir1.GetLength()<<"\nSide 1 = "<<cir1.GetSide1()<<
		"\nSide 2 = "<<cir1.GetSide2()<<"\n";
	cout<<"Radius ="<<cir2.GetRadius()<<"\nSquare = "<<cir2.GetSquare()<<
		"\nLength = "<<cir2.GetLength()<<"\nSide 1 = "<<cir2.GetSide1()<<
		"\nSide 2 = "<<cir2.GetSide2()<<"\n";
}