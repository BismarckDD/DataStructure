/*************************************************************************
 > File Name: TestHeap.cpp
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年09月20日 星期六 02时02分41秒
 ************************************************************************/

#include "Heap.cpp"
#ifndef _HEADERNAME_H
#define _HEADERNAME_H
#include<stdio.h>
#include<iostream>
using namespace std;
#endif

bool cmp(const int &a, const int &b)
{
	return a<b;
}
int main()
{
	int n;
	Heap<int> pq(100,cmp);
	for(int i=1;i<=10;++i)
	{
		scanf("%d",&n);
		pq.Push(n);
		if(i>=5) printf("%d\n",pq.Pop());
	}
	while(!pq.isEmpty())
		printf("%d\n",pq.Pop());
	return 0;
}
