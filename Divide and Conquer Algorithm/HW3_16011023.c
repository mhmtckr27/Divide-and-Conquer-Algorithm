#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED   "\x1B[31;1m"	//kirmizi yazi
#define GRN   "\x1B[32;1m"	//yesil	
#define YEL   "\x1B[33;1m"	//sari
#define BLU   "\x1B[34;1m"	//mavi
#define MAG   "\x1B[35;1m"	//magenta
#define CYN   "\x1B[36;1m"	//cyan
#define WHT   "\x1B[37;1m"	//beyaz
#define GRY "\x1B[30;1m"	//gri

#define N 6
int pivot = 0;

void printArray(int* dizi, int no);
void quickSort(int* dizi, int* dizi2, int n);
int partition(int *dizi, int lo, int hi);
int partition_r(int *dizi, int lo, int hi);
void qsort(int *dizi, int *dizi2, int lo, int hi);

int main()
{
	//int Key[N] = { 2,4,1,3,6,5 };
	//int Lock[N] = { 6,3,2,5,1,4 };
	int Key[N] = { 6,5,4,3,2,1 };
	int Lock[N] = { 6,5,4,3,2,1 };

	srand(time(NULL));
	system("color 85");
	printf(CYN"==============================================================\n"WHT);
	printArray(Key, 1);
	printArray(Lock, 0);
	printf(CYN"==============================================================\n");
	quickSort(Key, Lock, N);
	printf(CYN"==============================================================\n"WHT);
	printArray(Key, 1);
	printArray(Lock, 0);
	printf(CYN"==============================================================\n");
	system("PAUSE");
}

void printArray(int* dizi,int no)
{
	if (no) { printf("Key[N]: \t"); }
	else { printf("Lock[N]: \t"); }
	for (int i = 0; i < N; i++)
	{
		printf("%d ", dizi[i]);
	}
	printf("\n");
}

void quickSort(int* dizi,int* dizi2,int n)
{
	qsort(dizi,dizi2,0,n-1);
}

int partition(int *dizi, int lo, int hi) 
{
	pivot = dizi[hi];
	int i = lo - 1;	//dongu degiskeni
	int temp;	//swap islemi degiskeni
	for (int j = lo; j < hi; j++)
	{
		if (dizi[j] <= pivot)
		{
			++i;
			temp = dizi[i];
			dizi[i] = dizi[j];
			dizi[j] = temp;
		}
	}
	temp = dizi[i + 1];
	dizi[i + 1] = dizi[hi];
	dizi[hi] = temp;
	return i + 1;
}

int partition_r(int *dizi, int lo, int hi)
{
	srand(time(NULL));
	int r = lo + rand() % (hi - lo);
	int temp = dizi[r];
	dizi[r] = dizi[hi];
	dizi[hi] = temp;
	return partition(dizi, lo, hi);
}

void qsort(int *dizi, int *dizi2, int lo, int hi)
{
	int i = 0;	//while dongusu degiskeni
	if (lo < hi)
	{
		int p = partition_r(dizi, lo, hi);
		printf(CYN"==============================================================\n");
		printf(WHT"Pivot: %d \n", pivot);
		printf("Yazdirilan pivota gore key dizisi duzenleniyor...\n\n");
		printArray(dizi, 1);
		printArray(dizi2, 0);
		while (dizi2[i] != pivot) { ++i; }
		int temp = dizi2[i];	//swap i�lemi degiskeni
		dizi2[i] = dizi2[hi];
		dizi2[hi] = temp;
		p=partition(dizi2, lo, hi);
		printf(GRN"--------------------------------------------------------------\n");
		printf(WHT"Pivot: %d \n", pivot);
		printf("Yazdirilan pivota gore lock dizisi duzenleniyor...\n\n");
		printArray(dizi, 1);
		printArray(dizi2, 0);
		printf(CYN"==============================================================\n");
		qsort(dizi, dizi2, p+1, hi);
		qsort(dizi, dizi2, lo, p-1);
	}
}