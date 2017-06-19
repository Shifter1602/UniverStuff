class CRect
{
private:
	double m_width;
	double m_height;
	
public:
	CRect();
	CRect(double width, double height);
	~CRect();
	void SetWidth(double newwidth){m_width=newwidth;};
	double GetWidth(){return m_width;};
	void SetHeight(double newheight){m_height=newheight;};
	double GetHeight(){return m_height;};
	double GetSquare(){return m_width*m_height;};// вычисляет площадь
};

class CNewRect: public CRect
{
public:
	CNewRect();
	CNewRect(double width, double height);
	CNewRect(double side);
	~CNewRect();
	double GetPerimetr();
};

class CNewRect2: public CRect
{
public:
	CNewRect2();
	CNewRect2(double width, double height);
	~CNewRect2();
	
	double GetDiagLength();
	double GetRadius1();
	double GetRadius2();
};