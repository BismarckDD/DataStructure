/*************************************************************************
 > File Name: InsertionSort.cpp
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
void InsertionSort(T *arr, int n)
{
	for(int i=1,j,key;i<=n-1;++i)
	{
		key = arr[i];
		for(j=i;j>=1&&key<arr[j-1];--j)
			arr[j]=arr[j-1];
		arr[j] = key;
	}
}
int main()
{
	for(int i=0;i<MAXN;++i) arr[i]=rand();
	InsertionSort(arr,MAXN);
	for(int i=0;i<MAXN;++i) cout<<arr[i]<<endl;
	return 0;
}
