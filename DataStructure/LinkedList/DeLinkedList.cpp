/*************************************************************************
 > File Name: DeLinkedList.cpp
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年10月02日 星期四 14时00分54秒
 ************************************************************************/

#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

template<typename T>
struct node
{
	T data;
	node *next;
	node *prev;
};

template<typename T>
class LinkedList
{
	public:
		LinkedList()
		{
			this->_size = 0;
			this->_head = Create();
		}
		~LinkedList(){Free();}
		int size(){return this->_size;}
		int length();
		node<T> * Delete(T num);
		node<T> * Insert(T num);
		node<T> * Reverse();
		void print() const;
	private:
		void Free();
		node<T> * Create();
		node<T> *_head;
		int _size;
};

template<typename T>
void LinkedList<T>::Free()
{
	node<T> *curr = this->_head;
	node<T> *prev = NULL;
	while(curr!=NULL)
	{
		prev = curr;
		curr=curr->next;
		free(prev);
	}
}

template<typename T>
node<T> * LinkedList<T>::Create()
{
	node<T> *head, *prev, *curr;
	T data;
	if(cin>>data)
	{
		head=(node<T> *)malloc(sizeof(node<T>));
		head->data = data;
		head->prev = NULL;
		prev=head;
		++this->_size;
	}
	else
		return NULL;
	while(cin>>data)
	{
		curr=(node<T> *)malloc(sizeof(node<T>));
		curr->data = data;
		curr->prev = prev;
		prev->next = curr;
		prev = curr;
		++this->_size;
	}
	prev->next = NULL;
	return head;
}

template<typename T>
node<T> * LinkedList<T>::Insert(T num)
{
	node<T> *head=this->_head, *prev, *curr=head, *next;
	next = (node<T> *)malloc(sizeof(node<T>));
	next->data = num;
	if(head = NULL)
	{
		head = next;
		head->prev = NULL;
		head->next = NULL;
		this->_head = head;
		return head;
	}
	while(next->data>curr->data&&curr->next!=NULL)
	{
		prev = curr;
		curr = curr->next;
	}
	if(next->data<=curr->data)
	{
		if(curr==head)
		{
			head = next;
			next->prev = NULL;
			next->next = curr;
		    curr->prev = next;
		}
		else
		{
			prev->next = next;
			next->prev = prev;
			next->next = curr;
			curr->prev = next;
		}

	}
	else
	{
		curr->next = next;
		next->prev = curr;
		next->next = NULL;
	}
	this->_head=head;
	return head;
}
template<typename T>
node<T> * LinkedList<T>::Delete(T num)
{
	node<T> *head=this->_head, *prev, *curr=head;
	while(num!=prev->data&&curr->next!=NULL)
	{
		prev = curr;
		curr = curr->next;
	}
	if(num==curr->data)
	{
		if(curr==head)
		{
			head = head->next;
		    head->prev = NULL;
		}
		else
		{
			prev->next = curr->next;
		    curr->next->prev = prev;
		}
		free(curr);
	}
	else
		cout<<"没有找到"<<endl;
	this->_head = head;
	return head;
}


template<typename T>
int LinkedList<T>::length()
{
	int len = 0;
	node<T> *p = this->_head;
	while(p!=NULL)
	{
		p = p->next;
		++len;
	}
	return len;
}

template<typename T>
node<T> *LinkedList<T>::Reverse()
{
	node<T> *head = this->_head;
	if(head==NULL||head->next==NULL)
		return head;
	node<T> *prev, *curr, *next;
	prev = head;
	curr = head->next;
	head->prev = curr;
	while(curr)
	{
		next = curr->next;
		curr->next = prev;
		curr->prev = next;
		prev = curr;
		curr = next;
	}
	head->next = NULL;
	head = prev;
	return head;
}

template<typename T>
void LinkedList<T>::print() const
{
	node<T> *p = this->_head;
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p = p->next;
	}
	
}
int main()
{
	LinkedList<int> ll;
	ll.print();
	ll.Delete(6);
	ll.Insert(6);
	ll.Delete(6);
	return 0;
}

