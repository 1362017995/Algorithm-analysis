// 实验11贪心算法：最优前缀编码.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#define MAX 128
int v1, v2;
struct Tree {
	int lChild;
	int rChild;
	int root;
	int weight;
}tree[MAX];

void findMin(Tree tree[], int k) {
	//初始化v1
	for (int i = 0; i < k; ++i) {
		if (tree[i].root == -1) {
			v1 = i;
			break;
		}
	}
	//遍寻找到第一个权值最小的根节点
	for (int i = v1 + 1; i < k; i++)
		if (tree[i].root == -1 && tree[i].weight < tree[v1].weight)
			v1 = i;

	//初始化v2
	for (int i = 0; i < k; i++)
		if (tree[i].root == -1 && v1 != i) {
			v2 = i;
			break;
		}

	//遍寻找到第二个权值最小的根节点
	for (int i = v2 + 1; i < k; i++)
		if (tree[i].root == -1 && tree[i].weight < tree[v2].weight&&i != v1)
			v2 = i;
}
void Huffman(Tree tree[], int a[],int n,int k) {
	for (int i = 0; i < k; i++)
	{
		tree[i].root = -1;
		tree[i].lChild = -1;
		tree[i].rChild = -1;
	}
	for (int i = 0; i < n; i++)
		tree[i].weight = a[i];
	for (int i = n; i < k; i++) {
		findMin(tree, i);
		tree[i].weight = tree[v1].weight + tree[v2].weight;

		tree[v1].root = i;
		tree[v2].root = i;

		tree[i].lChild = v1;
		tree[i].rChild = v2;

	}
}
void printHuffman(Tree tree[],int k) {
	for (int i = 0; i < k; ++i) {
		printf_s("%7d", tree[i].weight);
		printf_s("%7d", tree[i].root);
		printf_s("%7d", tree[i].lChild);
		printf_s("%7d\n", tree[i].rChild);
	}
}
int main()
{
	int a[] = { 5,5,10,10,10,15,20,25 };
	Huffman(tree, a, 8, 15);
	printHuffman(tree, 15);
}

