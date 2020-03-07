// 实验二Dijkstra算法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
8
2000 1 2000 2000 2000 2000 2000 2000
2000 2000 2000 2 2000 2000 2000 2000
2 2000 2000 2000 2000 2000 2000 2000
2000 2000 1 2000 2000 8 2000 2000
2000 2000 2000 2 2000 2000 2 2000
2000 2000 2000 2000 2 2000 2000 2000
2000 2000 2000 2000 2000 3 2000 3
2000 2000 2000 2000 2000 2 2000 2000
*/

#include "pch.h"
#include <iostream>
#define MAXG 100

void Dijkstra(int a, int b, int n, int graph[][MAXG]) {
	int dis[MAXG], visit[MAXG], min_g, min_weight;
	for (int i = 0; i < n; i++)
	{
		dis[i] = graph[a][i];
		visit[i] = 0;
	}
	visit[a] = 1;
	for (int j = 0; j < n-2; j++) {
		min_weight = 2000;
		min_g = -1;
		for (int i = 0; i < n; i++){
			if (dis[i] < min_weight&&visit[i] == 0) {
			min_weight = dis[i];
			min_g = i;
			}
		}
		visit[min_g] = 1;
		for (int i = 0; i < n; i++){
			if (graph[min_g][i] + min_weight < dis[i] && visit[i] == 0) {
				dis[i] = graph[min_g][i] + min_weight;
			}
		}
	}
	printf("%d\n", dis[b]);
}

int main()
{
	int graph[MAXG][MAXG];
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; ++j) {
			scanf_s("%d", &graph[i][j]);
		}
	}
	Dijkstra(0, 7, n, graph);
}

