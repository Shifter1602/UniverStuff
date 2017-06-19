#include <iostream>
#include <math.h>
#include "room.h"
using namespace std;
void Room::GetParam() const 
{
	cout << " (" <<  x <<","<<  y <<","<< height <<"," << nWindow << ")";
}

double Room::Square()
{
	return x*y;
}

double Room::Volume()
{
	return x*y*height;
}

void Room::SetParam(double _x,double _y, double _h, int _n)
{
	if(_x<=MAX&&_x>=MIN)x=_x;
	else {cout<<"\nError x replaced by default";}
	if(_y<=MAX&&_y>=MIN)y=_y;
	else {cout<<"\nError y replaced by default";}
	if(_h<=MAX_H&&_h>=MIN_H)height=_h;
	else {cout<<"\nError height replaced by default";}
	if(_n<=MAX_W&&_n>=MIN_W)nWindow=_n;
	else {cout<<"\nError window replaced by default";}

}