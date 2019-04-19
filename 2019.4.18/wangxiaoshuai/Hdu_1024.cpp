#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1e6 + 5;
int data[N];
int dp[N];
int n,m;
int aux[N];
int main()
{
	while(~scanf("%d %d",&m,&n))
	{
		for(int i = 1; i <= n; i++)
		{
			scanf("%d",&data[i]);
		}
		mmset(dp,-0x3f);
		mmset(aux,-0x3f);
		int res = -0x3f3f3f3f;
		aux[0] = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m && j <= i; j++)
			{
				aux[j] = max(dp[j],aux[j]);
				dp[j] = max(dp[j],aux[j-1]) + data[i];
			}
				res = max(res,dp[m]);
			
		}
		printf("%d\n",res);
	}
	return 0;
}

