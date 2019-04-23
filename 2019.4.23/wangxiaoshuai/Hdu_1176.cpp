#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1e5 + 5;
int dp[N][15];
int data[N][15];
int n;
int main()
{
	while(~scanf("%d",&n) && n != 0)
	{
		int a,b;
		mmset(data,0);
		mmset(dp,0);
		int t = -1;
		for(int i = 1; i <= n; i++) 
		{
			scanf("%d %d",&a,&b);
			a++;
			data[b][a]++;
			t = max(t,b);
		}
		int res = -1;
		dp[1][5]  = data[1][5];
		dp[1][6] = data[1][6];
		dp[1][7] = data[1][7];
		for(int i = 2; i <= t; i++)
		{
			for(int j = 1; j <= 11; j++)
			{
				dp[i][j] = max(dp[i-1][j-1],max(dp[i-1][j],dp[i-1][j+1])) + data[i][j];
			}
			
		}
		for(int i = 1; i <= 11; i++)
		{
			res = max(res,dp[t][i]);
		}
		printf("%d\n",res);
	}
	
	
	return 0;
}
