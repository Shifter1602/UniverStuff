const int l_name = 30;
const int l_year = 5 ;
const int l_pay = 10 ;
const int l_buf = l_name + l_year + l_pay;
class Man {
public:
	Man(int lName = 30);
	~Man();
	bool CompareName(const char*) const;
	int GetBirthYear() const { return birth_year; }
	float GetPay() const { return pay; }
	char* GetName() const { return pName; }
	void Print() const;
	void SetBirthYear(const char*);
	void SetName(const char*);
	void SetPay(const char*);
private:
	char* pName;
	int birth_year;
	float pay;
};