#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct _TAddress
	{   char IPclass;
		int a[4];
		int freeBits;
		int Nbits;
		int Mbits;
	}   TAddress;

void FillPow2 (int pow2[])
	{   int i = 0;
		pow2[0] = 1;
		while (++i<25)
			pow2[i] = pow2[i-1]*2;
	}

int IsClass (char c)
	{   char *alphabet = "ABC";
		int i = strlen(alphabet);
		while (--i >-1)
		if (c == alphabet[i])
			return 1;
		return 0;
	}

TAddress *CreateAddress (char cl)
	{   TAddress *address = (TAddress*) malloc (sizeof(TAddress));
		address->IPclass = cl;
		address->a[0] = 255;
		address->a[1] = address->a[2] = address->a[3] = 0;

		if (cl == 'A') 
			address->freeBits = 24;
		else
			{   address->a[1] = 255;
		if (cl == 'B') 
			address->freeBits = 16;
		else
			{   address->a[2] = 255;
		address->freeBits = 8;
			}
	}
		address->Mbits = address->Nbits = -1;

		return address;
	}

void DeleteAddress (TAddress *address)
	{   free (address);
	}

void PrintAddress (TAddress *address)
	{   for (int i = 0; i<4; i++)
	printf("%3d.", address->a[i]);
printf("\n");
	}

void FillBits (TAddress *address, int N, int M, int pow2[])
	{   int i;
if (N)
	{   for (i = 0; i<25; i++)
	if (N <= pow2[i]-2)
		{   address->Nbits = i;
break;
	}
for (i = 0; i<25; i++)
	if (M <= pow2[i]-2)
		{   address->Mbits = i;
break;
	}
	}
else
	{   address->Nbits = 0;
address->Mbits = address->freeBits;
	}
	}

int CheckBits (TAddress *address)
	{   return address->Nbits + address->Mbits <= address->freeBits && address->Nbits>=0 && address->Mbits>0;
	}

int ai (int pow2[], int bits)
	{   int i = 0, sum = pow2[7];
while (++i < bits)
	sum += pow2[7-i];
return sum;
	}

void CreateMask (TAddress *address, int pow2[])
	{   if (!address->Nbits)
	return;
if (address->IPclass == 'C')
	{   address->a[3] = ai(pow2, address->Nbits);
return;
	}
if (address->IPclass == 'B')
	{   if (address->Nbits <= 8)
	{   address->a[2] = ai(pow2, address->Nbits);
return;
	}
	else
		{   address->a[2] = 255;
address->a[3] = ai(pow2, address->Nbits-8);
return;
	}   
	}
if (address->Nbits <= 8)
	{   address->a[1] = ai(pow2, address->Nbits);
return;
	}
else if (address->Nbits <= 16)
	{   address->a[1] = 255;
address->a[2] = ai(pow2, address->Nbits-8);
return;
	}
else
	{   address->a[1] = address->a[2] = 255;
address->a[3] = ai(pow2, address->Nbits-16);
return;
	}
	}


int main() 
	{   int pow2[25], N, M;
FillPow2 (pow2);
char cl;

do
	{   printf("Network class:\t");
	cl = toupper (getc(stdin));
	getc(stdin);
	} while (!IsClass (cl));

	TAddress *address = CreateAddress (cl);
	printf("Class standard mask:\t");
	PrintAddress (address);

	printf("\n\nNumber of subnetworks N = ");
	scanf ("%d", &N);
	printf("Maximum number of computers in one subnetwork M = ");
	scanf ("%d", &M);
	getc(stdin);

	FillBits (address, N, M, pow2);
	printf("Free bits: %d\tBits for subs: %d\tBits for comps: %d", address->freeBits, address->Nbits, address->Mbits);
	if (CheckBits (address))
		{   CreateMask (address, pow2);
	printf("\n\nThis configuration mask:\t");
	PrintAddress (address);
		}
	else
		printf("\n\nImpossible to create this configuration\n");

	DeleteAddress (address);
	getchar();
	return 0;
	}