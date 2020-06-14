#include<iostream>
#include<stdio.h>
#define MAX 128
int n;//圆的个数
double minlen = 10000, x[MAX], r[MAX];//分别为最小圆排列长度，每个圆心横坐标，每个圆半径
double bestr[MAX];//最小圆排列的半径顺序

double center(int t)//得到每个圆的圆心坐标
{
	double temp = 0;
	for (int j = 1; j < t; ++j)//存在跨圆相切的情况，所以循环判断
	{
		double value = x[j] + 2.0*sqrt(r[t] * r[j]);
		if (value > temp)
			temp = value;
	}
	return temp;
}
void compute()//计算最小排列长度
{
	double low = 0, high = 0;
	for (int i = 1; i <= n; ++i)//求出圆排序后的矩形左边框和右边框坐标
	{
		if (x[i] - r[i] < low)
			low = x[i] - r[i];
		if (x[i] + r[i] > high)
			high = x[i] + r[i];
	}
	if (high - low < minlen)//更新minlen和bestr数组
	{
		minlen = high - low;
		for (int i = 1; i <= n; ++i)
			bestr[i] = r[i];
	}
}
void backtrack(int t)
{
	if (t == n+1)
	{
		compute();
	}
	else
	{
		for (int j = t; j <= n; ++j)
		{
			double temp;//全排列
			temp = r[t];
			r[t] = r[j];
			r[j] = temp;
			double centerx = center(t);
			if (centerx + r[t] + r[1] < minlen)//因为第一个圆的圆心坐标为0，所以要加上r[1]
			{
				x[t] = centerx;
				backtrack(t + 1);
			}
			temp = r[t];
			r[t] = r[j];
			r[j] = temp;
		}
	}
}
int main()
{
	printf_s("请输入圆的个数：");
	scanf_s("%d", &n);
	printf_s("请输入每个圆的半径：");
	for (int i = 1; i <= n; ++i) {
		scanf_s("%lf", &r[i]);
	}
	backtrack(1);
	printf_s( "最小圆排列长度为：%lf\n",minlen);
	printf_s("最优圆排列的顺序对应的半径分别为：");
	for (int i = 1; i <= n; ++i) {
		printf_s("%lf ", bestr[i]);
	}
    printf_s("\n");
	return 0;
}