// 实验七动态规划投资问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*
4 5
0 11 12 13 14 15
0 0 5 10 15 20
0 2 10 30 32 40
0 20 21 22 23 24
*/

#include "pch.h"
#include <iostream>
#define MAX 128

void Invest(int f[][MAX],int n,int m) {
	//f用于存放项目与投资之间的效益关系，如f[1][2]，表示对第一个项目投资两万元产生的效益
	//F用于存放产生的最大效益，例如F[3][2]，表示有3个项目时，投资2万元产生的最大效益
	//A用于存放产生最大效益时，给第k个项目分配的资金
	int F[MAX][MAX] = { 0 }, A[MAX][MAX] = { 0 }, max;
	for (int k = 1; k <= n; k++)
	{
		for (int x = 1; x <= m; x++) {
			//求得最大效益
			max = 0;
			for (int xk = 0; xk <= x; xk++)
			{

				if (F[k - 1][x - xk] + f[k][xk] > max)
				{
					max = F[k - 1][x - xk] + f[k][xk];
					A[k][x] = xk;
				}
			}
			F[k][x] = max;
		}
	}
	//输出F数组
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; ++j) {
			printf_s("%d ", F[i][j]);
		}
		printf_s("\n");
	}
	//输出A数组
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; ++j) {
			printf_s("%d ", A[i][j]);
		}
		printf_s("\n");
	}
}
int main()
{
	int f[MAX][MAX] = { 0 };
	int m, n;
	scanf_s("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; ++j) {
			scanf_s("%d", &f[i][j]);
		}
	}
	Invest(f, n, m);
}
