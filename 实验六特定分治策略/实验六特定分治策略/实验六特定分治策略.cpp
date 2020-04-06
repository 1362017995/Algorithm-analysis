// 实验六特定分治策略.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*输入例子
5
3 5 7 9 1
2
20
10 12 13 14 15 16 17 11 38 19 20 1 2 3 31 34 5 18 4 9
11
*/

#include "pch.h"
#include <iostream>
#define MAX 128
void quickSort(int a[], int left, int right) {
	int pivot, i, j;
	int temp;
	if (left < right)
	{
		i = left; j = right + 1;
		pivot = a[left];
		do {
			do {
				i++;
			} while (a[i] < pivot);
			do {
				j--;
			} while (a[j] > pivot);
			if (i < j) {
				int temp;
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		} while (i < j);
		int temp;
		temp = a[left];
		a[left] = a[j];
		a[j] = temp;
		quickSort(a, left, j - 1);
		quickSort(a, j + 1, right);
	}
}

int Select(int a[], int start,int end,int k) {
	int m=0;//记录有多少组
	int s[MAX];//用于保存中位数
	int i = start;
	while(i <= end){//对数组进行分组
		int iend = i + 4;
		if (iend >= end) {
			iend = end;
		}
		quickSort(a, i, iend);
		s[m] = a[(i + iend) / 2];//找出每组中位数
		m++;
		i = iend+1;
	}
	quickSort(s, 0, m - 1);//对中位数进行排序
	int mid = s[m / 2];
	int al[MAX], ar[MAX];
	int count_al = 0, count_ar = 0;
	for (int j = start; j <= end; j++)//通过m*，将数组分为两部分
	{
		if (a[j]<mid)
		{
			al[count_al++] = a[j];
		}
		else if (a[j] > mid)
		{
			ar[count_ar++] = a[j];
		}
	}
	if (k==count_al+1)
	{
		return mid;
	}
	else if (k<= count_al)
	{
		return Select(al, 0, count_al - 1, k);
	}
	else
	{
		return Select(ar, 0, count_ar - 1, k - count_al-1);
	}
}

int main()
{
	int a[MAX];
	int n,k;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	scanf_s("%d", &k);
	printf_s("%d", Select(a, 0, n - 1, k));
}

