// 实验一Prim算法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*输入示例
5 16
0 1 5
0 2 3
0 4 10
1 0 5
1 2 5
1 3 7
2 0 3
2 1 5
2 3 11
2 4 8
3 1 7
3 2 11
3 4 10
4 0 10
4 2 8
4 3 10*/
/*
6 12
0 1 1
0 5 1
1 0 1
1 2 4
2 1 4
2 3 3
3 2 3
3 4 5
4 3 5
4 5 2
5 4 2
5 0 1
*/

#include "pch.h"
#include <iostream>
#include<stdlib.h>

typedef struct graph *graphPoint;
typedef struct graph {
	int nextbiao, quan;
	graphPoint link;
};

graphPoint *first;
int g, v;
int *visit;
void Insert(graphPoint *p, int nextbiao, int quan) {
	graphPoint temp;
	temp = (graphPoint)malloc(sizeof(graph));
	temp->nextbiao = nextbiao;
	temp->quan = quan;
	temp->link = *p;
	*p = temp;
}
void create() {//创建图
	int biao, nextbiao, quan;
	scanf_s("%d %d", &g, &v);
	first = (graphPoint*)malloc(sizeof(graph)*g);
	visit = (int*)malloc(sizeof(int)*g);
	for (int i = 0; i < g; ++i) {
		first[i] = NULL;
		visit[i] = 0;
	}
	for (int i = 0; i < v; i++)
	{
		scanf_s("%d %d %d", &biao, &nextbiao, &quan);
		Insert(&first[biao], nextbiao, quan);
	}
}

void prim(int x) {
	int min, minbiao, i, sumweight = 0;
	graphPoint temp;
	visit[x] = 1;
	for (int j = 0; j < g-1; j++) {
		min = 1000;
		for (i = 0; i < g; i++)
		{
			if (visit[i] == 1) {
				for (temp = first[i]; temp; temp = temp->link)
				{
					if (visit[temp->nextbiao] == 1)//用于判断该点是否已被访问过
					{
						continue;
					}
					else if (temp->quan < min)
					{
						min = temp->quan;
						minbiao = temp->nextbiao;
					}
				}

			}
		}
		visit[minbiao] = 1;
		sumweight = sumweight + min;
	}
	printf_s("the minmum weight is %d.", sumweight);
}



int main()
{
	create();
	prim(0);
}

