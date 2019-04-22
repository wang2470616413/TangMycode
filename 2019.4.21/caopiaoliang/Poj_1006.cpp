#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;
int Extended_Euclid(int a,int b,int &x,int &y)    //扩展欧几里得算法
{
	int d;
	if(b==0)
	{
		x=1;y=0;
		return a;
	}
	d=Extended_Euclid(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
 
int Chinese_Remainder(int a[],int w[],int len)    //中国剩余定理  a[]存放余数  w[]存放两两互质的数
{
	int i,d,x,y,m,n,ret;
	ret=0;
	n=1;
	for (i=0;i<len;i++)
		n*=w[i];
	for (i=0;i<len;i++)
	{
		m=n/w[i];
		d=Extended_Euclid(w[i],m,x,y);
		ret=(ret+y*m*a[i])%n;
	}
	return (n+ret%n)%n;
}
 
int main()
{
	int p , e , i , d ,num = 1;
	int a[5] , m[5];
	m[0] = 23;
	m[1] = 28;
	m[2] = 33;
	while(~scanf("%d %d %d %d" , &p , &e , &i , &d) && (p!=-1&&e!=-1&&i!=-1&&d!=-1))
	{
		ll ans;
		a[0] = p;
		a[1] = e;
		a[2] = i; 
		int op = Chinese_Remainder(a , m , 3);
		if(op <= d)
		{
			ans = 23*28*33-d+op;
		}
		if(op > d)
		{
			ans = op-d;
		}
		printf("Case %d: the next triple peak occurs in %d days.\n" , num , ans);
		num++;
	}	
	return 0;
} 
