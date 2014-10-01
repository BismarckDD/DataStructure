/*************************************************************************
 > File Name: BubbleSort.cpp
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
void BubbleSort(T *arr, int n)
{
	bool flag;
	for(int i=0;i<=n-2;++i)
	{
		flag = false;
		for(int j=n-1;j>=i+1;--j)
			if(arr[j]<arr[j-1])
			{
			//	int temp = arr[j];
			//	arr[j] = arr[j-1];
			//	arr[j-1] = temp;
				arr[j]   = arr[j]^arr[j-1];
				arr[j-1] = arr[j]^arr[j-1];
				arr[j]   = arr[j]^arr[j-1];
				flag = true;
			}
		if(!flag) return ;
	}
}

int main()
{
	for(int i=0;i<MAXN;++i) arr[i]=rand();
	BubbleSort(arr,MAXN);
	for(int i=0;i<MAXN;++i) cout<<arr[i]<<endl;
	return 0;
}
