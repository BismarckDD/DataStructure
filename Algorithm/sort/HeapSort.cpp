/*************************************************************************
 > File Name: HeapSort.cpp
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年10月01日 星期三 16时10分12秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include"../../DataStructure/Heap/Heap.cpp"
using namespace std;
	
const int MAXN = 100;
int arr[MAXN];

template<typename T>
void HeapSort(T *arr, int n)
{
	Heap<int> heap(n+10);
	for(int i=0;i<n;++i) heap.Push(arr[i]);
	for(int i=0;i<n;++i) arr[i] = heap.Pop();
}

int main()
{
	for(int i=0;i<MAXN;++i) arr[i]=rand();
	HeapSort(arr,MAXN);
	for(int i=0;i<MAXN;++i) cout<<arr[i]<<endl;
	return 0;
}
