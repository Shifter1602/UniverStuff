class CCircle
{
private:
	double m_radius;
public:
	CCircle();
	~CCircle();
	CCircle(double radius);

	void SetRadius(double newradius){m_radius=newradius;};
	double GetRadius(){return m_radius;};

	double GetSquare(){return m_radius*m_radius;};// вычисляет площадь
};

class CNewCircle: public CCircle
{
public:
	CNewCircle();
	~CNewCircle();
	CNewCircle(double radius);

	double GetLength();
	double GetSide1();
	double GetSide2();
};