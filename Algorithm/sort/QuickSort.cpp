/*************************************************************************
 > File Name: QuickSort.cpp
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年10月01日 星期三 16时10分12秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
	
const int MAXN = 100;
int arr[MAXN];

template<typename T>
int parition(T *arr, int l,int r)
{
	int k = l+(rand()%(r-l));
	int key = arr[l];
	int i=l,j=r;
	while(i<j)
	{	
		while(i<j&&arr[j]>=key) --j;
		if(i<j) arr[i++] = arr[j];
		while(i<j&&arr[i]<=key) ++i;
		if(i<j) arr[j--] = arr[i];
	}
	arr[i] = key;
	return i;
}

template<typename T>
void QuickSort(T *arr, int l, int r)
{
	if(l<r)
	{
		int key = parition(arr,l,r);
		QuickSort(arr,l,key-1);
		QuickSort(arr,key+1,r);
	}
}

int main()
{
	for(int i=0;i<MAXN;++i) arr[i]=rand();
	QuickSort(arr,0,MAXN-1);
	for(int i=0;i<MAXN;++i) cout<<arr[i]<<endl;
	return 0;
}
