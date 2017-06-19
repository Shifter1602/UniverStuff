#pragma once
#include <iostream>
const double MIN=2,MAX=25,MIN_H=1.7,MAX_H=3.5,MAX_W=5,MIN_W=0;
class Room
{
	double x,y,height;
	int nWindow;
public:
	Room(double _� = 10, double _� = 10, double _h =10, double nW=2) : x(_�), y(_�), height(_h),nWindow(nW) {}
	double Square();
	double Volume();
	void GetParam() const;
	void SetParam(double _x,double _y, double _h, int _n);

};