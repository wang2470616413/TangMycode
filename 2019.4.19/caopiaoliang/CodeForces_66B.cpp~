#include <iostream>
#include <stdio.h>
const int maxn = 1e3+8;
int a[maxn];
using namespace std;
int main()
{
	int n , ans , op = 0;
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; i++)
	{
		scanf("%d" , &a[i]);
	}
	for(int i = 1 ; i <= n ; i++)
	{
		ans=0;
		for(int j = i ; j > 1 ; j--)
		{
			if(a[j] >= a[j-1]) ans++;
			else break;
		}
		for(int j = i ; j < n ; j++)
		{
			if(a[j+1] <= a[j])ans++;
			else break;
		}
		op = max(op , ans);
	}
	printf("%d\n" , op+1);
	return 0;
 } 
