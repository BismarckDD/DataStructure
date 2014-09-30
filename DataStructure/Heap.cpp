#ifndef _HEADERNAME_H
#define _HEADERNAME_H
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
#endif

template<typename T>
class Heap
{
	private:
		T *heap;
		int curSize;
		int maxSize;
		static const int root = 1;
		bool (* func)(const T &v1, const T &v2);
		static bool cmp(const T &v1, const T &v2)
		{
			return v1<v2;
		}
		void DoubleSize()
		{
			this->maxSize <<= 1;
			this->heap = (T *)realloc(heap,sizeof(T)*(maxSize+1));
		}
        void Swap(T &v1, T &v2)
	    {
			if(v1==v2) return;
			v1 = v1^v2;
			v2 = v1^v2;
			v1 = v1^v2;
		}
        void AdjustDown(int s)
	    {
			int t = s<<1;
			T tmp = this->heap[s];
			while(t<=curSize)
			{
				if(t+1<=curSize&&func(heap[t+1],heap[t])) ++t;
				if(!func(tmp,heap[t]))
					heap[s] = heap[t];
				else
					break;
				s = t;
				t = s<<1;
			}
			heap[s]=tmp;
         
	    }
		void AdjustUp(int s)
        {
			int t = s>>1;
			T tmp = heap[s];
			while(t>=1)
			{
				if(func(tmp,heap[t]))
				    heap[s] = heap[t]; 
				else
					break;
				s = t;
				t = s>>1;
			}
			heap[s]=tmp;
		}
	public:
		Heap(int size=100,bool (* func)(const T &v1,const T &v2) = &Heap<T>::cmp) 
			//默认构造参数，另外可以使用new (this)Heap(100)的语法
		{
		    this->maxSize = size;
			//printf("%d\n",this->maxSize);
			this->curSize = 0;
			this->heap=NULL;
			this->heap=(T *)malloc(sizeof(T)*(this->maxSize+1));
		    if(heap==NULL) printf("Error\n");
			this->func = func;
		}
		//Heap(){new (this)Heap(100);} 不能直接用Heap(100)
		~Heap(){if(heap!=NULL) free(heap);}
		void Push(T key)
		{
			++this->curSize;
			if(this->curSize == this->maxSize) DoubleSize();
			this->heap[this->curSize] = key;
			AdjustUp(this->curSize);
		}
		T Pop()
	    {
			Swap(heap[1],heap[this->curSize]);
			--this->curSize;
			AdjustDown(this->root);
			return heap[this->curSize+1];
		}
		bool isEmpty()
		{
			return this->curSize == 0;
		}
	
};
/*bool cmp(const int &a, const int &b)
{
	return a>b;
}
int main()
{
	Heap<int> pq(100000,cmp);
    for(int i=0;i<100000;++i)
        pq.Push(rand());
	for(int i=0;i<100000;++i)
		printf("%d\n",pq.Pop());
    return 0;
}*/
