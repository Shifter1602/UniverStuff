class CCircle
{
private:
	double m_radius;
	double CalcSquare(double radius);

public:
	CCircle();
	CCircle(double radius);
	~CCircle();

	void SetRadius();
	void GetRadius();
	void ShowSquare();
	bool InCircle();
};