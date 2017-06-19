const int l_FName = 15;
const int l_LName = 15;
const int l_Address = 30;
const int l_Phone = 10;
const int l_buf= l_FName+l_LName+l_Phone;
class Notebook
{
public:
	Notebook();
	~Notebook();
	char* GetFName() const { return pFName; }	
	char* GetLName() const { return pLName; }
	char* GetAddress() const { return pAddress; }
	char* GetPhone() const {return pPhone;}
	void Print() const;
	void SetFName(const char*);
	void SetLName(const char*);
	void SetAddress(const char*);
	void SetPhone(const char*);
private:
	char *pName,*pFName, *pLName, *pAddress;
	char *pPhone;///
};