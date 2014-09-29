/*************************************************************************
 > File Name: SuffixExpression.cpp
 > Author: BismarckDD
 > Mail: BismarckDD@foxmail.com 
 > Created Time: 2014年09月25日 星期四 18时37分01秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

const int MAXN = 300;
struct NODE
{
	bool type;
	char op;
	int value;
}stack2[MAXN];
char stack1[MAXN];
int stack[MAXN];
int top,top1,top2;
char str[1000];
bool cmp(const char op1, const char op2)
{//逆波兰表达式必须op2>op1
	if(op1=='(') return true;
	if(op2=='*'||op2=='/')
		if(op1=='+'||op1=='-')
			return true;
		else
			return false;
	else
		return false;
}
int cal(const int a, const int b, const char op)
{
	switch(op)
	{
		case '+':return a+b;break;
		case '-':return a-b;break;
		case '*':return a*b;break;
		case '/':return a/b;break;
	    default:cout<<"没见过这个字符"<<endl;break;
	}
}
void Calculate(const char *src)
{
    int len = strlen(src);
	int num = 0;
	top = top1 = top2 = -1;
	for(int i=0;i<len;++i)
	{
		if(src[i]<='9'&&src[i]>='0') //value
		{
			num *= 10;
			num += src[i]-'0';
		}
		else if(src[i]=='('||src[i]==')')//kuohao
		{
			if(src[i]=='(') 
			{
				stack1[++top1]=src[i];
				continue;
			}
			else
			{
				if(i!=0&&src[i-1]!=')')
				{
					stack2[++top2].type = false;
					stack2[top2].value = num;
					num = 0;
				}
				while(stack1[top1]!='(')
				{
					stack2[++top2].type = true;
					stack2[top2].op = stack1[top1--];
				}
				--top1;
			}
		}
		else
		{
           	if(i!=0&&src[i-1]!=')')
			{
				stack2[++top2].type = false;
				stack2[top2].value = num;
				num = 0;
			}
			if(top1==-1||cmp(stack1[top1],src[i]))
				stack1[++top1]=src[i];
			else
			{
				while(top1>=0&&!cmp(stack1[top1],src[i]))
				{
					stack2[++top2].type = true;
				    stack2[top2].op = stack1[top1--];
				}
				stack1[++top1]=src[i];
			}
		}
	}
	if(len!=0&&src[len-1]!=')')
	{
		stack2[++top2].type = false;
		stack2[top2].value = num;
		num = 0;
	}
	while(top1>=0)
	{
		stack2[++top2].type = true;
		stack2[top2].op = stack1[top1--];
	}
	for(int i=0;i<=top2;++i)
	{
		if(stack2[i].type)
		{
			int b = stack[top--];
			int a = stack[top--];
			cout<<stack2[i].op;
			stack[++top] = cal(a,b,stack2[i].op);
			//cout<<a<<","<<b<<","<<stack2[i].op<<endl;
		}
		else
		{
			cout<<stack2[i].value;
			stack[++top]= stack2[i].value;
		}
	}
	cout<<endl;
	cout<<stack[top]<<endl;
}
int main()
{
	scanf("%s",str);//要求表达式必须合法
	Calculate(str);
	return 0;
}
