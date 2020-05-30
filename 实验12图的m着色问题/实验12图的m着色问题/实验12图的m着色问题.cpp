// 实验12图的m着色问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#define MAX 128
int n, m;//点和颜色数目
int graph[MAX][MAX] = {0};
int color[MAX] = { 0 };
int a, b;
int sum = 0;//方案数
bool canSet(int x) {
	for (int k = 1; k <= n; ++k) {
		if (graph[x][k] && color[x] == color[k]) {
			return false;
		}
	}
	return true;
}
void set_color(int x){
	if (x>n) {
		for (int i = 1; i <= n; i++)
		{
			printf_s("%d ", color[i]);
		}
		sum++;
		printf_s("\n");
	}
	else {
		for (int i = 1; i <= m; ++i) {
			color[x] = i;
			if (canSet(x)) {
				set_color(x+1);
			}
			color[x] = 0;
		}
	}
}
int main()
{
	//初始化
	scanf_s("%d %d", &n, &m);
	while (scanf_s("%d %d", &a, &b) != EOF && a != 0 && b != 0)
	{
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	set_color(1);
	if (sum==0)
	{
		printf_s("NO\n");
	}
	else {
		printf_s("方案数 = %d\n", sum);
	}
	return 0;
}