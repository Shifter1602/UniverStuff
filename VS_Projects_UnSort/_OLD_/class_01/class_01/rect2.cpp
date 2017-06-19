#include <iostream>
#include <conio.h>
#include <math.h>
#include "rect2.h"
using namespace std;

CRect::CRect()
{
	cout<<"Constructor Default of CRect is working...\n";
	m_width=m_height=0;
}
CRect::CRect(double width, double height)
{
	cout<<"Constructor 2 of CRect is working...\n";
	m_width=width;
	m_height=height;
}
CRect::~CRect()
{
	cout<<"Destructor  CRect is working...\n";
}
//------------------------------------------------

CNewRect::CNewRect()
{
	cout<<"Constructor Default of CNewRect is working...\n";
	SetWidth(0);
	SetHeight(0);
}

CNewRect::CNewRect(double width, double height)
{
	cout<<"Constructor 2 of CNewRect is working...\n";
	SetWidth(width);
	SetHeight(height);
}

CNewRect::CNewRect(double side)
{
	cout<<"Constructor 3 of CNewRect is working...\n";
	SetWidth(side);
	SetHeight(side);
}

CNewRect::~CNewRect()
{
	cout<<"Destructor  CNewRect is working...\n";
}

double CNewRect::GetPerimetr()
{
	return 2*(GetWidth()+GetHeight());
}

//--------------------------------------------------------------

CNewRect2::CNewRect2()
{
	cout<<"Constructor Default of CNewRect2 is working...\n";
	SetWidth(0);
	SetHeight(0);
}

CNewRect2::CNewRect2(double width, double height)
{
	cout<<"Constructor 2 of CNewRect is working...\n";
	SetWidth(width);
	SetHeight(height);
}

CNewRect2::~CNewRect2()
{
	cout<<"Destructor  CNewRect2 is working...\n";
}


double CNewRect2::GetDiagLength()
 {
	 return (GetWidth()+GetHeight())/2;
 }

double CNewRect2::GetRadius1()
{
	return sqrt(GetWidth()*GetWidth()+GetHeight()*GetHeight())/2;
}

double CNewRect2::GetRadius2()
{
	if(GetWidth()<GetHeight())
		return GetWidth()/2;
	else return GetHeight()/2;
}



//=========================================================
void main()
{
/*
	CRect rect1,rect2(3,4);
	rect1.SetWidth(10);
	rect1.SetHeight(15);
	cout<<"Width ="<< rect1.GetWidth() << "\nHeight = " << rect1.GetHeight() << "\nSquare = " <<rect1.GetSquare();
	cout<<"Width ="<< rect2.GetWidth() << "\nHeight = " << rect2.GetHeight() << "\nSquare = " <<rect2.GetSquare();

	CNewRect newrect1,newrect2(3,4),newrect3(3);
	newrect1.SetWidth(10);
	newrect1.SetHeight(15);
	cout<<"Width ="<< newrect1.GetWidth() << "\nHeight = " << newrect1.GetHeight() << "\nSquare = " <<newrect1.GetSquare()<<"\nPerimetr ="<<newrect1.GetPerimetr()<<"\n";
	cout<<"Width ="<< newrect2.GetWidth() << "\nHeight = " << newrect2.GetHeight() << "\nSquare = " <<newrect2.GetSquare()<<"\nPerimetr ="<<newrect2.GetPerimetr()<<"\n";
	cout<<"Width ="<< newrect3.GetWidth() << "\nHeight = " << newrect3.GetHeight() << "\nSquare = " <<newrect3.GetSquare()<<"\nPerimetr ="<<newrect3.GetPerimetr()<<"\n";
*/
	CNewRect2 newrect1;
	newrect1.SetWidth(10);
	newrect1.SetHeight(15);
	cout<<"Width ="<< newrect1.GetWidth() << "\nHeight = " << newrect1.GetHeight() << "\nDiagonal = " <<newrect1.GetDiagLength() << "\nRadius1 = " <<newrect1.GetRadius1()<< "\nRadius2 = " << newrect1.GetRadius2() << "\n";

}