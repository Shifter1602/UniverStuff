#include "elementy.h"
using namespace std;

void main()
{
	CombDevice a(3, 1);
	bool b[3] = {1,0,1};
	a.SetInputValue(b);
	CombDevice c(a);
	cout<<c.GetOutputValue()<<endl;
	system("pause");
}