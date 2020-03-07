// 实验二Floyd算法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
4
0 2 6 4
2000 0 3 2000
7 2000 0 1
5 2000 12 0
*/

#include "pch.h"
#include <iostream>
#define MAXG 100

void fun(int n, int graph[][MAXG]) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf_s("%d ", graph[i][j]);
		}
		printf_s("\n");
	}
	printf_s("\n");
}

void Floyd(int n,int graph[][MAXG]) {
	int A[MAXG][MAXG];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; ++j) {
			A[i][j] = graph[i][j];
		}
	}
	for (int v = 0; v < n; v++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n;++j) {
				if (A[i][j] > A[i][v] + A[v][j]) {
					A[i][j] = A[i][v] + A[v][j];
				}
			}
		}
	}
	fun(n, A);
}

int main()
{
	int n;
	int graph[MAXG][MAXG];
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n;++j) {
			scanf_s("%d", &graph[i][j]);//输入图，如果点i到点j没有直接路径，输入无穷大
		}
	}
	Floyd(n,graph);
	return 0;
}


