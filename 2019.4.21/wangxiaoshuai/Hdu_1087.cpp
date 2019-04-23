#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long
#define mmset(a,b) memset(a,b,sizeof(a)) 
using namespace std;
const int N  = 1e3 + 5;
ll data[N] , dp[N]; 
int n;
int main()
{
	while(~scanf("%d",&n) && n != 0)
	{
		for(int i = 1; i <= n; i++)
		{
			scanf("%lld",&data[i]);
		}
		data[0] = -1;
		mmset(dp,0) ;
		ll res = -1;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 0; j < i; j++)
			{
				if(data[i] > data[j])
				{
					dp[i] = max(dp[i], dp[j] + data[i]);
				}
			}
			res = max(dp[i],res);
		}
		printf("%lld\n",res);
	}	
	
	
	
	
	return 0;
}
