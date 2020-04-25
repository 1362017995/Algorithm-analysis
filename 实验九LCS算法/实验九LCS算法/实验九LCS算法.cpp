// 实验九LCS算法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*
4 3
A B C D
B A C
5 4
A B C D E
B D C A
*/

#include "pch.h"
#include <iostream>
#define MAX 128
char X[MAX], Y[MAX];
int C[MAX][MAX] = { 0 }, B[MAX][MAX] = { 0 };
int m, n;
void f(int B[][MAX],int i,int j) {
	if (i == 0 || j == 0) {
		return;
	}
	if (B[i][j] == 2) {
		f(B, i - 1, j-1);
		printf("%c ", X[i]);
	}
	else if (B[i][j] == 1) {
		f(B, i - 1, j);
	}
	else {
		f(B, i, j-1);
	}
}

void LCS(char X[],int m,char Y[],int n,int C[][MAX],int B[][MAX]) {
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; ++j) {
			if (X[i] == Y[j]) {
				C[i][j] = C[i - 1][j - 1] + 1;
				B[i][j] = 2;//2表示删除两个，1表示删除x，0表示删除y
			}
			else
			{
				if (C[i - 1][j] > C[i][j - 1])
				{
					C[i][j] = C[i - 1][j];
					B[i][j] = 1;
				}
				else {
					C[i][j] = C[i][j - 1];
					B[i][j] = 0;
				}
			}
			//printf_s("%d ", B[i][j]);
		}
		//printf_s("\n");
	}
	f(B, m, n);
}

int main()
{
	scanf_s("%d %d", &m, &n);//表示X,Y的长度
	for (int i = 1; i <= m; i++)
	{
		scanf_s(" %c", &X[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		scanf_s(" %c", &Y[i]);
	}
	LCS(X, m, Y, n, C, B);
}

