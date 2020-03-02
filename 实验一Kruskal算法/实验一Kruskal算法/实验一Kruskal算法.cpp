// 实验一Kruskal算法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*输入示例
8
0 1 5
0 2 3
0 4 10
1 2 5
1 3 7
2 3 11
2 4 8
3 4 10*/
/*
6
0 1 1
1 2 4
2 3 3
3 4 5
4 5 2
5 0 1
*/

#include "pch.h"
#include <iostream>
#define MAXG 100

int find_root(int x, int parent[]) {
	int x_root = x;
	while (parent[x_root] != -1)
	{
		x_root = parent[x_root];
	}
	return x_root;
}
/*1-successfully,0-failed*/
int union_g(int x, int y, int parent[]) {
	int x_root = find_root(x, parent);
	int y_root = find_root(y, parent);
	if (x_root == y_root) {
		return 0;
	}
	else
	{
		parent[x_root] = y_root;
		return 1;
	}
}

struct g
{
	int a;
	int b;
	int weight;
}edge[MAXG*(MAXG - 1) / 2];

int main()
{
	int parent[MAXG];
	int v;
	scanf_s("%d", &v);
	for (int i = 0; i < MAXG; i++)
	{
		parent[i] = -1;
	}
	for (int i = 0; i < v; i++)
	{
		scanf_s("%d %d %d", &edge[i].a, &edge[i].b, &edge[i].weight);
	}
	for (int i = 0; i < v; i++)
	{
		for (int j = 1; j < v - i; j++)
		{
			if (edge[j].weight < edge[j - 1].weight)
			{
				int temp;
				temp = edge[j].weight;
				edge[j].weight = edge[j - 1].weight;
				edge[j - 1].weight = temp;
				temp = edge[j].a;
				edge[j].a = edge[j - 1].a;
				edge[j - 1].a = temp;
				temp = edge[j].b;
				edge[j].b = edge[j - 1].b;
				edge[j - 1].b = temp;
			}
		}
	}
	int sumweight = 0;
	for (int i = 0; i < v; i++)
	{
		if (union_g(edge[i].a, edge[i].b, parent) == 1) {
			sumweight = sumweight + edge[i].weight;
		}
		else
		{
			continue;
		}
	}
	printf_s("the minmum weight is %d.", sumweight);
	return 0;
}

