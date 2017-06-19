#include <iostream>
#include <random>
using namespace std;

class Strategy
	{
	public:
		virtual ~Strategy() {}
		virtual void use(int *arr, int size) = 0;
	};

class Strategy_1: public Strategy
	{
	public:
		void use(int *arr, int size)
			{
				int min, max, pos;
				cout << "Sorted Array" << endl;
				for(int i = 0; i < size; i++){ 
					pos = i; 
					min = arr[i];
					for(int j = i + 1; j < size; j++){                  
						if (arr[j] < min) {
							pos = j; 
							min = arr[j]; 
							}
						}
					arr[pos] = arr[i]; 
					arr[i] = min;
					cout<<arr[i]<<" ";
					}
				cout << endl;
			};
	};

class Strategy_2: public Strategy
	{
	public:
		void use(int *arr, int size)
			{
			int min, max, pos;
			cout << "Sorted Array" << endl;
			for(int i = 0; i < size; i++){ 
				pos = i; 
				max = arr[i];
				for(int j = i + 1; j < size; j++){ 
					if (arr[j] > max) {
						pos = j; 
						max = arr[j]; 
						}
					}
				arr[pos] = arr[i];
				arr[i] = max;
				cout<<arr[i]<<" ";
				}
			cout << endl;
			};
	};


class Context
	{
	protected:
		Strategy* operation;

	public:
		virtual ~Context() {}
		virtual void useStrategy(int *arr, int size) = 0;
		virtual void setStrategy(Strategy* v) = 0;
	};

class Client: public Context
	{
	public:
		void useStrategy(int *arr, int size)
			{
			operation->use(arr,size);
			}

		void setStrategy(Strategy* o)
			{
			operation = o;
			}
	};

int * CreateArray(int size)
	{
	int *arr = new int[size];
	cout << "ARRAY" << endl;
	for (int i=0;i<size;i++)
		{
		int r = rand() % 100 +1;
		arr[i]=r;
		cout << arr[i] << " ";
		}
	cout << endl;
	return arr;
	}

int main()
	{
	cout << "Input Size" << endl;
	int size;
	cin >> size;
	int *arr,*arr1;
	arr = CreateArray(size);
	arr1=arr;


	
	
	Client customClient;
	Strategy_1 str1;
	Strategy_2 str2;


	customClient.setStrategy(&str1);
	customClient.useStrategy(arr,size);
	customClient.setStrategy(&str2);
	customClient.useStrategy(arr1,size);


	int b;cin >> b;

	return 0;
	}