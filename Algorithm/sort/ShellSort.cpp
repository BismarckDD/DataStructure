/*************************************************************************
 > File Name: ShellSort.cpp
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年10月01日 星期三 16时00分12秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

const int MAXN = 100;
int arr[MAXN];

template<typename T>
void ShellPass(T *arr,int n,int d)
{
	for(int j,i=d,tmp;i<=n-1;++i)
	{
		tmp = arr[i];
		for(j=i;j>=d&&tmp<arr[j-d];j=j-d)
			arr[j]=arr[j-d];
		arr[j] = tmp;
	}
}
template<typename T>
void ShellSort(T *arr,int n,int d)
{
	int increment = d;
	do{
		increment = increment/3+1;
		ShellPass(arr,n,increment);
	}while(increment>1);
}
int main()
{

	for(int i=0;i<MAXN;++i) arr[i]=rand();
	ShellSort(arr,MAXN,5);
	for(int i=0;i<MAXN;++i) cout<<arr[i]<<endl;
	return 0;
}


