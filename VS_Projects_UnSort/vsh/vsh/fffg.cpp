#include <iostream>
#include <random>
using namespace std;

int main()
	{
/*
	char *s,s1;
	s = new char[0];
	cin >> s;
	cout << s << endl;*/
	int b,r=0; cin >> b;
	r=rand() % 100 + 1;
	while (1)
		{
			r=rand() % 100 + 1;
			if((r<=b+30) && (r>=b-30))
				break;
		}
	cout << r;
	int a; cin >> a;

	}