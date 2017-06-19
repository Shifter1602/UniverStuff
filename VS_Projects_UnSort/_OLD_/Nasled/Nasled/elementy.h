#pragma once
#include <iostream>

class Element
{
public:
	Element(int aInput, int aOutput): m_nInput(aInput), m_nOutput(aOutput)
	{m_pElName = NULL;}
	
	~Element()
	{
		if (m_pElName != NULL)
			delete [] m_pElName;
	}

	void SetName(char* name)
	{
		m_pElName = name;
	}
public:
	char* m_pElName;
	unsigned int m_nInput;
	unsigned int m_nOutput;
};

class CombDevice: public Element
{
public:
	bool* m_pInputValue;
	CombDevice(int aInput, int aOutput): Element(aInput, aOutput){}
	CombDevice(CombDevice& aComb): Element(aComb.m_nInput, aComb.m_nOutput)// конструктор копирования
	{
		if (this == &aComb)
			return;
		m_pInputValue = new bool [m_nInput];
		for (int i = 0; i<m_nInput; i++)
			m_pInputValue[i] = aComb.m_pInputValue[i];
	}
	~CombDevice()
	{
		delete [] m_pInputValue;
	}
	void SetInputValue(bool* aIV)
	{
		m_pInputValue = aIV;
	}
	bool GetValue(unsigned int index)
	{
		return m_pInputValue[index-1];
	}
	bool GetOutputValue()
	{
		bool a = false;
		for (unsigned int i=0; i<m_nInput; i++) 
		{
			a =a || m_pInputValue[i] ;
		}
		return a;
	}
};
//JK
class Memory: public Element
{
public:
	static bool* m_pInputValues;
	bool Q;
	bool neQ;
	Memory(): Element(3,1)
	{
		m_pInputValues = NULL;
		Q=0;
		neQ=0;
	}
	~Memory()
	{
		if(m_pInputValues != NULL)
			delete [] m_pInputValues;
	}
	Memory(Memory& aMem): Element(aMem.m_nInput, aMem.m_nOutput)
	{
		if (this == &aMem)
			return;
		Q = aMem.Q;
		neQ = aMem.neQ;
	}
};
