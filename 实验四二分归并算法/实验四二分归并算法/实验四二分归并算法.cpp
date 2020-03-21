// 实验四二分归并算法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#define MAX_SIZE 100
void merge(int a[],int b[],int start,int middle,int end) {
	for (int i = start; i <=end; i++)
	{
		b[i] = a[i];
	}
	int starta, startb, enda, endb,i=start;
	starta = start;
	enda = middle;
	startb = middle + 1;
	endb = end;
	while (starta<=enda&&startb<=endb)
	{
		if (b[starta]<b[startb])
		{
			a[i++] = b[starta++];
		}
		else
		{
			a[i++] = b[startb++];
		}
	}
	while (starta <= enda)
	{
		a[i++] = b[starta++];
	}
	while (startb <= endb)
	{
		a[i++] = b[startb++];
	}
}
void mergeSort(int a[],int b[],int start,int end) {
	int middle;
	if (start<end)
	{
		middle = start + (end - start) / 2;
		mergeSort(a,b,start, middle);
		mergeSort(a,b,middle + 1, end);
		merge(a,b,start, middle, end);
	}
}

int main()
{
	int a[MAX_SIZE], n, b[MAX_SIZE];
	scanf_s("%d", &n);
	for (int i = 0; i <n; ++i) {
		scanf_s("%d", &a[i]);
	}
	mergeSort(a,b, 0, n-1);
	for (int i = 0; i <n; ++i) {
		printf_s("%d ", a[i]);
	}
}
