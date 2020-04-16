// 实验八矩阵链的乘法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
5
30 35 15 5 10 20
*/

#include "pch.h"
#include <iostream>
#define MAX 128
int f(int s[][MAX],int start, int end) {//用于输出划分的位置
	int t;
	t = s[start][end];
	if (end-start<=1) {
		return NULL;
	}
	else {
		printf_s("%d,%d:%d\n", start, end, t);
		f(s, start, t);
		f(s, t + 1, end);
	}
}
void g(int p[],int m[][MAX],int s[][MAX], int n) {
	int j, min;
	for (int r = 2; r <= n; ++r) {//问题规模
		for (int i = 1; i <= n - r + 1; i++)//i为起点
		{
			j = i + r - 1;
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];//划分为Ai（Ai+1...Aj）的情况
			s[i][j] = i;
			for (int k = i + 1; k <= j - 1; k++) //不同的划分位置
			{
				min = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (min < m[i][j]) {
					m[i][j] = min;
					s[i][j] = k;
				}
			}
		}
	}
}
int main()
{
	int p[MAX], m[MAX][MAX] = { 0 }, s[MAX][MAX] = { 0 };
	int n;
	scanf_s("%d", &n);//表示有多少个矩阵
	for (int i = 0; i <= n;++i) {
		scanf_s("%d", &p[i]);
	}
	g(p,m, s, n);
	printf_s("%d\n", m[1][n]);
	f(s, 1, n);
	return 0;
}

