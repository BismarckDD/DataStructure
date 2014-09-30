#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;
const int MAXN = 1000000;
int n,a[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)
	a[i]=rand();
    sort(a,a+n);
    for(int i=0;i<n;++i)
	printf("%d ",a[i]);
    printf("\n");
    return 0;
}
