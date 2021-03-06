/*************************************************************************
 > File Name: bs3.cpp 返回key值的最大下标
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年09月30日 星期二 15时02分17秒
 ************************************************************************/


#include<stdio.h>
#include<iostream>
using namespace std;

int arr[16] = {1,2,2,3,3,3,4,4,4,4,5,5,5,6,6,7};
int bSearch(int *arr, int l,int r,int key)
{
	while(l<=r)
	{
		int	m = (l+r)>>1;
		if(arr[m]==key) 
		{
			if(m==r) return m;
			if(m<=r-1&&arr[m+1]!=key) return m;
			else l=m+1;
		}
		else if(arr[m]<key) l=m+1;
		else if(arr[m]>key) r=m-1;
	}
	return -1;
}
int main()
{
	cout<<bSearch(arr,0,15,1)<<endl;
	cout<<bSearch(arr,0,15,2)<<endl;
	cout<<bSearch(arr,0,15,3)<<endl;
	cout<<bSearch(arr,0,15,4)<<endl;
	cout<<bSearch(arr,0,15,5)<<endl;
	cout<<bSearch(arr,0,15,6)<<endl;
	cout<<bSearch(arr,0,15,7)<<endl;
	return 0;
}
