/*************************************************************************
 > File Name: SelectionSort.cpp
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
void SelectionSort(T *arr, int n)
{
	for(int i=0,j,k,key;i<=n-2;++i)
	{
		key = arr[i];
		k = i;
		for(j=i+1;j<=n-1;++j)
			if(arr[j]<key)
			{
				key = arr[j];
			    k = j;
			}
		if(k!=i)
		{
			arr[i] = arr[i]^arr[k];
			arr[k] = arr[i]^arr[k];
			arr[i] = arr[i]^arr[k];
		}
	}
}

int main()
{
	for(int i=0;i<MAXN;++i) arr[i]=rand();
	SelectionSort(arr,MAXN);
	for(int i=0;i<MAXN;++i) cout<<arr[i]<<endl;
	return 0;
}
