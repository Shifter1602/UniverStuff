#include <iostream>
#include <conio.h>

using namespace std;
class cList
	{
	class Node
		{
		public:
			int d;
			Node *next;
			Node *prev;
			Node(int dat=0){d=dat;next=prev=0;}
		};
	Node *pbeg,*pend;
	public:
		cList(){pbeg=pend=0;}
		~cList();
		void add(int d);
		Node *find(int i);
		Node *insert(int key,int d);
		bool remove(int key);
		void print();
		void print_back();
	};

void cList::add(int d)
	{
	Node *pv=new Node(d);
	if(pbeg)
		{
		pv->prev=pend;
		pend->next=pv;
		pend=pv;
		}
	else pbeg=pend=pv;
	}

cList::Node *cList::find(int i)
	{
	Node *pv=pbeg;
	while(pv)
		{
		if(pv->d==i) break;
		pv=pv->next;
		}
	return pv;
	}

cList::Node *cList::insert(int key,int d)
	{
	 if(Node *pkey=find(key))
		 {
		 Node *pv=new Node(d);
		 pv->next=pkey->next;
		 pv->prev=pkey;
		 pkey->next=pv;
		 if(pkey!=pend) (pv->next)->prev=pv;
		 else pend=pv;
		 return pv;
		 }
	}

bool cList::remove(int key)
	{
	if(Node *pkey = find(key))
		{
		if(pkey==pbeg)
			{
			pbeg=pbeg->next;
			pbeg->prev=0;
			}
		else if(pkey==pend)
			{
			pend=pend->prev;
			pend->next=0;
			}
		else
			{
			(pkey->prev)->next=pkey->next;
			(pkey->next)->prev=pkey->prev;
			}
		delete pkey;
		return true;
		}
	return false;
	}

void cList::print()
	{
	Node *pv=pbeg;
	cout << endl;
	while(pv)
		{
		cout << pv->d << " ";
		pv=pv->next;
		}
	cout << endl;
	}

void cList::print_back()
	{
	Node *pv=pend;
	cout << endl;
	while(pv)
		{
		cout << pv->d << " ";
		pv=pv->prev;
		}
	cout << endl;
	}

cList::~cList()
	{
	if(pbeg)
		{
		Node *pv=pend;
		while(pv)
			{
			pv=pv->next;
			delete pbeg;
			pbeg=pv;
			}
		}
	}

int main()
	{
	cList L;
	for(int i=0;i<=5;i++)
		L.add(i);
	L.print();L.print_back();
	L.insert(2,200);
	if(!L.remove(5)) cout << "chetyre nol' chetyre Not Found!!!";
	L.print();L.print_back();
	_getch();
	}
