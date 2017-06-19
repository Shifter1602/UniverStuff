#include <iostream>
#include <conio.h>
using namespace std;

template <class Data> class RingList
	{
	class Node
		{
		public:
		Node *next;
		Data d;//,*pd;
		/*Node(Data* dat=0)
			{
				pd=new Data[];
				//cout << sizeof(dat) << endl;
				if(sizeof(dat)==sizeof(Data))
					pd[0]=*dat;
				/ *else
					{
					for (int i=0;i<sizeof(*dat); i+=sizeof(Data))
						{
						pd[i]=*dat;
						}
					}* /
				next=this;
			}*/
		Node(Data dat)
			{
			d=dat;
			next=this;
			}
		};
		Node *pbeg;
	public:
		void add(Data d);
		//void add(Data *d);
		inline RingList(){pbeg=0;}
		void print();
	};

template <class Data> void RingList<Data>::add(Data d)
	{
			Node *pv = new Node(d);
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
template <class Data> void RingList<Data>::add(Data *pd)
	{
	Node *pv = new Node(pd);
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

	}*/

template <class Data> void RingList<Data>::print()
	{
		Node *pv=pbeg;
		do 
		{
		cout << pv->d << " " << typeid(pv->d).name() << endl;
		pv=pv->next;
		}
		while (pv!=pbeg);
		
	}

void main()
	{
	RingList<int> a;
	a.add(3);
	a.add(4);
	a.add(5);
	a.print();
	RingList<double> d;
	d.add(3.5);
	d.add(2.28);
	d.add(1.337);
	d.print();
	
	
	_getch();
	}