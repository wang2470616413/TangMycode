#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n , k , x, a[200] , op ,ans = 0, count;
	scanf("%d %d" , &n , &k);
	a[n+1] = k;
	for(int i = 1 ; i <= n ; i++)
	{
		scanf("%d" , &a[i]);
	}
	sort(a+1 , a+1+n);

	while(a[1] != k)
	{
		for(int i = 1 ; i <= n ; i++)
		{	
			if(a[i] != a[i+1])
			{
				a[i]++;
			}
		}
		ans++;
	}
	printf("%d\n" , ans);
	return 0;
 } 
