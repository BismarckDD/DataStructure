/*************************************************************************
 > File Name: MergeSort.cpp
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
int temp[MAXN];
template<typename T>
void Merge(T *arr, int l,int r)
{
	int m = (l+r)>>1;
	int i=l,j=m+1,k = l;
	while(i<=m&&j<=r)
	{
		if(arr[i]<arr[j]) temp[k++] = arr[i++];
		else temp[k++] = arr[j++];
	}
	while(i<=m) temp[k++] = arr[i++];
	while(j<=r) temp[k++] = arr[j++];
	for(int i=l;i<=r;++i) arr[i] = temp[i];
}

template<typename T>
void MergeSort(T *arr, int l, int r)
{
	if(l<r)
	{
		int m = (l+r)>>1;
		MergeSort(arr,l,m);
		MergeSort(arr,m+1,r);
		Merge(arr,l,r);
	}
}

int main()
{
	for(int i=0;i<MAXN;++i) arr[i]=rand();
	MergeSort(arr,0,MAXN-1);
	for(int i=0;i<MAXN;++i) cout<<arr[i]<<endl;
	return 0;
}
