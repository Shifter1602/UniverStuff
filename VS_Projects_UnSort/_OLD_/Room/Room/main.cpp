#include <iostream>
#include "room.h"
using namespace std;
int main()
{
	Room room1;
	room1.GetParam();
	room1.SetParam(-1,2,3,4);
	room1.GetParam();
	cout<<"\nSquare "<<room1.Square()<<"\n Volume "<< room1.Volume()<<"\n";
}