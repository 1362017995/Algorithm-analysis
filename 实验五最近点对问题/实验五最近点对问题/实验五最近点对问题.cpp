// 实验五最近点对问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
5
1 1
1 2
2 3
3 1
5 2

6
1 1
1 1.5
3 1
4 2
4 4
5 1
*/
#include "pch.h"
#include <iostream>
#define MAXG 128
#define MAX 10000

struct MyStruct
{
	double x;
	double y;
}P[MAXG];

double dis(MyStruct a, MyStruct b) {
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
double min(double a, double b) {
	return a > b ? b : a;
}

double efficientClosestPair(MyStruct P[],int n) {
	double dminsq = MAX, m, d,dl,dr;
	MyStruct s[MAXG];
	MyStruct Pl[MAXG], Pr[MAXG];
	int num = 0;
	if (n<=3) {
		for (int i = 0; i < n-1; i++)
		{
			for (int j = i+1; j < n;j++) {
				dminsq = min(dis(P[i], P[j]), dminsq);
			}
		}
	}
	else
	{
		for (int i = 0; i < n/2; i++)
		{
			Pl[i].x = P[i].x;
			Pl[i].y = P[i].y;
		}
		for (int j = n/2; j < n; j++)
		{
			Pr[j-n/2].x = P[j].x;
			Pr[j-n/2].y = P[j].y;
		}
		dl=efficientClosestPair(Pl, n / 2);
		dr=efficientClosestPair(Pr, n-n / 2);
		d = min(dl, dr);
		m = P[n / 2].x;
		for (int i = 0; i < n; i++)
		{
			if (P[i].x-m<d)
			{
				s[num++] = P[i];
			}
		}
		for (int i = 0; i < num-1; i++)
		{
			int k = i + 1;
			while (k<=num-1 && dis(s[k],s[i])<dminsq)
			{
				dminsq = dis(s[k], s[i]);
				k++;
			}
		}
	}
	return dminsq;
}

int main()
{
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%lf %lf", &P[i].x, &P[i].y);
	}
	printf_s("%f", efficientClosestPair(P, n));
}

