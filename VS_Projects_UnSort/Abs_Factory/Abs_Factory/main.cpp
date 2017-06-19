// AbstractFactory.cpp: определяет точку входа для консольного приложения.
//

//#include "stdafx.h"
#include <iostream>
#include <conio.h>

class ICar //AbstractProductA
	{
	public:
		virtual void printName() = 0;
		virtual ~ICar() {}
	};

class Ford: public ICar //ConcreteProductA1
	{
	public:
		virtual void printName() 
			{ 
			std::cout << "Ford" << std::endl; 
			}
	};

class Toyota: public ICar // ConcreteProductA2
	{
	public:
		virtual void printName() 
			{ 
			std::cout << "Toyota" << std::endl; 
			}
	};

class Mersedes: public ICar // ConcreteProductA2
	{
	public:
		virtual void printName() 
			{ 
			std::cout << "Mersedes" << std::endl; 
			}
	};

class IEngine // AbstractProductB
	{
	public:
		virtual void printPower() = 0;
		virtual ~IEngine(){}
	};

class FordEngine: public IEngine // ConcreteProductB1
	{
	public:
		virtual void printPower() 
			{ 
			std::cout << "Ford Engine 4.4" << std::endl; 
			}
	};

class ToyotaEngine: public IEngine // ConcreteProductB2
	{
	public:
		virtual void printPower() 
			{ 
			std::cout << "Toyota Engine 3.2" << std::endl; 
			}
	};

class MersedesEngine: public IEngine // ConcreteProductB2
	{
	public:
		virtual void printPower() 
			{ 
			std::cout << "Mersedes Engine over 9000" << std::endl; 
			}
	};

class IBus // AbstractProductC
	{
	public:
		virtual void printBus() = 0;
		virtual ~IBus(){}
	};

class FordBus: public IBus // ConcreteProductC1
	{
	public:
		virtual void printBus() 
			{ 
			std::cout << "Ford Bus" << std::endl; 
			}
	};

class ToyotaBus: public IBus // ConcreteProductC2
	{
	public:
		virtual void printBus() 
			{ 
			std::cout << "Toyota Bus" << std::endl; 
			}
	};

class MersedesBus: public IBus // ConcreteProductC2
	{
	public:
		virtual void printBus() 
			{ 
			std::cout << "Mersedes Bus" << std::endl; 
			}
	};

class ICarFactory // AbstractFactory
	{
	public:
		virtual ICar*    createCar()    = 0;
		virtual IEngine* createEngine() = 0;
		virtual IBus* createBus() = 0;
	};

class FordFactory: public ICarFactory // ConcreteFactory1
	{
	public:

		virtual ICar* createCar() // from ICarFactory
			{
			return new Ford();
			}

		virtual IEngine* createEngine()
			{
			return new FordEngine();
			}

		virtual IBus* createBus()
			{
			return new FordBus();
			}
	};

class ToyotaFactory: public ICarFactory // ConcreteFactory2
	{
	public:
		virtual ICar* createCar() // from ICarFactory
			{
			return new Toyota();
			}

		virtual IEngine* createEngine()
			{
			return new ToyotaEngine();
			}

		virtual IBus* createBus()
			{
			return new ToyotaBus();
			}
	};


class MersedesFactory: public ICarFactory // ConcreteFactory2
	{
	public:
		virtual ICar* createCar() // from ICarFactory
			{
			return new Mersedes();
			}

		virtual IEngine* createEngine()
			{
			return new MersedesEngine();
			}

		virtual IBus* createBus()
			{
			return new MersedesBus();
			}
	};

void use(ICarFactory* f)
	{
	ICar*     myCar     =  f->createCar();
	IEngine*  myEngine  =  f->createEngine();

	myCar->printName();
	myEngine->printPower();

	delete myCar;
	delete myEngine;
	}



int main()
	{
	ToyotaFactory toyotaFactory;
	FordFactory fordFactory;
	MersedesFactory mersedesFactory;
	use (&toyotaFactory);
	use (&fordFactory);
	use (&mersedesFactory);

	getch();

	return 0;
	}

