#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1e4 + 5;
int v1,v2,v; 
int dp[N],C[N],W[N];
int n;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&v1,&v2);
		v = v2  - v1;
		scanf("%d",&n);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d %d",&W[i],&C[i]);
		}
		mmset(dp,0x3f);
		dp[0] = 0;
		for(int i = 1; i <= n; i ++)
		{
			for(int j = C[i]; j <= v; j++)
			{
				dp[j] = min(dp[j],dp[j - C[i]] + W[i]);
			}
		}
		if(dp[v] == 0x3f3f3f3f)
		{
			printf("This is impossible.\n");
		}
		else
		{
			printf("The minimum amount of money in the piggy-bank is %d.\n",dp[v]);
		}
		
	}
	
	
	return 0;
} 
