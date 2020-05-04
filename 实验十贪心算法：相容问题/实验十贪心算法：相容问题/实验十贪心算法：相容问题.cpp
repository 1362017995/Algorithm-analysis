// 实验十贪心算法：相容问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*
10
1 4
3 5
2 6
5 7
4 9
5 9
6 10
8 11
8 12
2 13
*/

#include "pch.h"
#include <iostream>
#define MAX 128
struct Show{
	int start;
	int end;
	int time;
}A[MAX];

void sort(Show A[],int n) {
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 1; j < n - i; j++)
		{
			if (A[j - 1].end > A[j].end)
			{
				int temp = A[j - 1].end;
				A[j - 1].end = A[j].end;
				A[j].end = temp;
				temp = A[j - 1].start;
				A[j - 1].start = A[j].start;
				A[j].start = temp;
				temp = A[j - 1].time;
				A[j - 1].time = A[j].time;
				A[j].time = temp;
			}
		}
	}
}

int f(Show A[],int n) {
	int k = 1;
	int lastend = A[0].end;
	for (int i = 1; i < n; i++)
	{
		if (A[i].start > lastend)
		{
			k++;
			lastend = A[i].end;
		}
	}
	return k;
}

int main()
{
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &A[i].start);
		scanf_s("%d", &A[i].end);
		A[i].time = A[i].end - A[i].start;
	}
	sort(A,n);
	printf_s("%d", f(A, n));
}

