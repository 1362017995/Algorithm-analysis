/*
10
1 2 3 4 5 6 7 8 9 10
*/


#include "pch.h"
#include <iostream>

int Order_search(int A[], int n, int key) {
	for (int i = 0; i < n; i++)
	{
		if (A[i] == key) {
			return i;
		}
	}
	return 0;
}

int Binary_search(int A[], int n, int key) {
	int a, b, x;
	a = 0;
	b = n-1;
	x = (a + b) / 2;
	while (a<b)
	{
		if (A[x] == key) {
			return x;
		}
		else
		{
			if (A[x] > key) {
				b = x - 1;
			}
			else
			{
				a = x + 1;
			}
		}
		x = (a + b) / 2;
	}
	return 0;
}

int main()
{
	int n,a[100];
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	printf("%d\n", Order_search(a, n, 7));
	printf("%d\n", Binary_search(a, n, 8));
}
