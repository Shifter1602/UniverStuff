#include <iostream>;
using namespace std;
#define LEN 3
void arr_swap(int **arr,int a, int b,int c,int d)
	{
		arr[a][b]=arr[c][d];
		arr[c][d]=0;
	}
void print(int ** arr)
	{
	for(int i=0;i<LEN;i++)
		{
		cout << endl;
		for	(int j=0;j<LEN;j++)
			cout << arr[i][j] << " ";
		}
	}
void arr_swap2(int ** arr)
	{
	1;	
	}

void main()
	{
	int start[LEN][LEN] = {{1,2,3},{4,5,6},{7,8,0}};
	int **a=new int*[LEN];
	for (int i=0;i<LEN;i++)
		a[i] = new int [LEN];
	for(int i=0;i<LEN;i++)
		for	(int j=0;j<LEN;j++)
			a[i][j]=start[i][j];
	print(a);
	arr_swap(a,LEN-1,LEN-1,1,1);
	print(a);
	int b;
	cin >> b;
	//arr_swap(&a,)

	}