#include <iostream>
#include <conio.h>
using namespace std;

class Book
	{
	public:
		int _nUDK,_year,_quantity;
		char *_FIO,*_title;
		Book *next;
		Book(int nUDK=0,char *FIO="",char *title="",int year=0,int quantity=0)
			: _nUDK(nUDK), _year(year), _quantity(quantity)
			{
			_FIO=strcpy(new char[strlen(FIO)+1],FIO);
			_title=strcpy(new char[strlen(title)+1],title);
			next=this;
			}
		Book& operator=(Book& b)
			{
				_nUDK=b._nUDK;
				_year=b._year;
				_quantity=b._quantity;
				_FIO=strcpy(new char[strlen(b._FIO)+1],b._FIO);
				_title=strcpy(new char[strlen(b._title)+1],b._title);
				return *this;
			}
		bool take(Book* pbeg,int nUDK)
			{	
				Book *pv=pbeg;
				do 
				{
				if((pv->_nUDK)==nUDK)
					{
					if((pv->_quantity)<=0)
						{
						cout << "Book is out of Stock" << endl;
						return false;
						}

					pv->_quantity-=1;
					return true;
					}
				pv=pv->next;
				} while (pv!=pbeg);
				return false;
			}
		bool get_back(Book* pbeg,int nUDK)
			{	
			Book *pv=pbeg;
			do 
			{
			if((pv->_nUDK)==nUDK)
				{
				pv->_quantity+=1;
				return true;
				}
			pv=pv->next;
			}
			while (pv!=pbeg);
			return false;
			}
		void show_all()
			{
			cout << this->_nUDK << " " << this->_FIO << " "	<< this->_title << " " << this->_year << " " << this->_quantity << endl; 
			}
		bool show_quantity(Book* pbeg,int nUDK)
			{
			Book *pv=pbeg;
			do 
			{
			if((pv->_nUDK)==nUDK)
				{
				cout << pv->_quantity << endl;
				return true;
				}
			pv=pv->next;
			}
			while (pv!=pbeg);
			cout << "Book not Found!" << endl;
			return false;
			}

	};

template <class Data> class Node
	{
	public:
		Node *next;
		Data d;
		Node(Data dat=0)
			{
			d=dat;
			next=this;
			}
		void show_all()
			{
				cout << d << " " << typeid(Data).name() << " " << sizeof(Data)  << endl;
			}

	};

template <class Data> class RingList : public Book
	{
		/*class Node
		{
		public:
		Node *next;
		Data d;
		Node(Data dat)
			{
			d=dat;
			next=this;
			}
		};*/
		//Node * _pbeg;
		
	public:
		Data * pbeg;
		//void add(Data d);
		void add(Data *d);
		RingList()
			{
			pbeg=nullptr;
			//_pbeg=nullptr;
			}
		void print();
		bool Take(int nUDK);
		bool Get_back(int nUDK);
		bool Show_quantity(int nUDK);
		//void print_();
	};

template <class Data> void RingList<Data>::add(Data *d)	//ÑÑÛËÎ×ÍÛÉ ÒÈÏ
	{
			Data *pv = d;
			if(pbeg==0)
				{
				pbeg=pv;
				}
			else if ((pbeg->next)==pbeg)
				{
				pv->next = pbeg;
				pbeg->next=pv;
				}
			else
				{
				pv->next=pbeg->next;
				pbeg->next=pv;
				}
	}

/*
template <class Data> void RingList<Data>::add(Data d) //NODE
	{
	Node *pv = new Node(d);
	if(_pbeg==0)
		{
		_pbeg=pv;
		}
	else if ((_pbeg->next)==_pbeg)
		{
		pv->next = _pbeg;
		_pbeg->next=pv;
		}
	else
		{
		pv->next=_pbeg->next;
		_pbeg->next=pv;
		}
	}*/


template <class Data> void RingList<Data>::print()
	{
			Data *pv=pbeg;
			do 
				{
				pv->show_all();
				pv=pv->next;
				}
				while (pv!=pbeg);
	}
template <class Data> bool RingList<Data>::Take(int nUDK)
	{
		Data *pv=pbeg;
		do 
			{
			if(pv->take(pv,nUDK))
			  return true;
			pv=pv->next;
			}
			while (pv!=pbeg);
			return false;
	}
template <class Data> bool RingList<Data>::Get_back(int nUDK)
	{
	Data *pv=pbeg;
	do 
		{
		if(pv->get_back(pv,nUDK))
			return true;
		pv=pv->next;
		}
		while (pv!=pbeg);
		return false;
	}
template <class Data> bool RingList<Data>::Show_quantity(int nUDK)
	{
		Data *pv=pbeg;
		do 
			{
			if(pv->show_quantity(pv,nUDK))
				return true;
			pv=pv->next;
			}
			while (pv!=pbeg);
			return false;
	}
			/*if(typeid(&pv)==typeid(Book))
				{
				do 
					{
					pv->show();
					pv=pv->next;
					}
					while (pv!=pbeg);
				}
			else
				{
				do 
					{
					cout << pv << " " << typeid(*pv).name() << " " << sizeof(*pv)  << endl;
					pv=pv->next;
					}
					while (pv!=pbeg);
				}*/
				

/*
template <class Data> void RingList<Data>::print_()
	{
	Node *pv=_pbeg;
	do 
		{
		cout << pv->d << " " << typeid(*pv).name() << " " << sizeof(*pv) << endl;
		pv=pv->next;
		}
		while (pv!=_pbeg);
	}*/
	
	
	

void main()
	{
	/*RingList<Node<int>> a;
	a.add(&(Node<int>(10)));
	a.add(&(Node<int>(20)));
	a.add(&(Node<int>(30)));
	a.add(4);
	a.add(5);
	a.print();*/
	/*RingList<double> d;
	d.add(3.5);
	d.add(2.28);
	d.add(1.337);
	d.print_();*/
	RingList<Book> b; 
	b.add(&(Book(1,"Puskin","Sochineniya",1999,10)));
	b.add(&(Book(2,"Gogol","Mertvye Dushi",1944,14)));
	b.add(&(Book(3,"Avtor 1","Kniga 1",1944,0)));
	b.print();
	cout << endl;
	b.Take(2);
	b.print();
	cout << endl;
	b.Get_back(1);
	b.print();
	cout << endl;
	b.Show_quantity(3);
	cout << endl;
	b.Show_quantity(2);
	cout << endl;
	b.Take(3);

	_getch();
	}