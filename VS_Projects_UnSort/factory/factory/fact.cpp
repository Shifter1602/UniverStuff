#include <iostream>
using namespace std;
class IUnit
	{
	protected:
	int strength;
	public:
	//virtual void SetStrength(int str){}
	int get_str(){return strength;};
	};

class Archer : public IUnit
	{
	public:
	Archer(){strength=3;};
	};

void main()
	{
	Archer a;
	cout << a.get_str() << endl;
	int b; cin >> b;
	}
