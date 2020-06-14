#include<iostream>
#include<stdio.h>
#define MAX 128
int n;//Բ�ĸ���
double minlen = 10000, x[MAX], r[MAX];//�ֱ�Ϊ��СԲ���г��ȣ�ÿ��Բ�ĺ����꣬ÿ��Բ�뾶
double bestr[MAX];//��СԲ���еİ뾶˳��

double center(int t)//�õ�ÿ��Բ��Բ������
{
	double temp = 0;
	for (int j = 1; j < t; ++j)//���ڿ�Բ���е����������ѭ���ж�
	{
		double value = x[j] + 2.0*sqrt(r[t] * r[j]);
		if (value > temp)
			temp = value;
	}
	return temp;
}
void compute()//������С���г���
{
	double low = 0, high = 0;
	for (int i = 1; i <= n; ++i)//���Բ�����ľ�����߿���ұ߿�����
	{
		if (x[i] - r[i] < low)
			low = x[i] - r[i];
		if (x[i] + r[i] > high)
			high = x[i] + r[i];
	}
	if (high - low < minlen)//����minlen��bestr����
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
			double temp;//ȫ����
			temp = r[t];
			r[t] = r[j];
			r[j] = temp;
			double centerx = center(t);
			if (centerx + r[t] + r[1] < minlen)//��Ϊ��һ��Բ��Բ������Ϊ0������Ҫ����r[1]
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
	printf_s("������Բ�ĸ�����");
	scanf_s("%d", &n);
	printf_s("������ÿ��Բ�İ뾶��");
	for (int i = 1; i <= n; ++i) {
		scanf_s("%lf", &r[i]);
	}
	backtrack(1);
	printf_s( "��СԲ���г���Ϊ��%lf\n",minlen);
	printf_s("����Բ���е�˳���Ӧ�İ뾶�ֱ�Ϊ��");
	for (int i = 1; i <= n; ++i) {
		printf_s("%lf ", bestr[i]);
	}
    printf_s("\n");
	return 0;
}