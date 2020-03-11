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
	int a[] = { 0,1,2,3,4,5,6,7,8,9 };
	printf("%d\n", Order_search(a, 10, 7));
	printf("%d\n", Binary_search(a, 10, 8));
}
