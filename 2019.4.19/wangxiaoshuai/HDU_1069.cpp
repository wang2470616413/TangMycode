#include<stdio.h>
#include<string.h>
#include<algorithm>
#define  ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1005;
struct node
{
	int a,b,h;
	node()
	{
		
	};
	node(int p_a, int p_b, int p_h)
	{
		a = p_a;
		b = p_b;
		h = p_h;
	};
	bool operator < (node two) const
	{
		return a < two.a && b < two.b;
	}
};
node data[N];
int dp[N]; 
int n;
void addData(int a, int b, int c, int &len)
{
	data[len++] = node(a,b,c);
	data[len++] = node(a,c,b);
	data[len++] = node(b,c,a);
	data[len++] = node(b,a,c);
	data[len++] = node(c,a,b);
	data[len++] = node(c,b,a);
}
bool cmp(node one, node two)
{
	return one.a == two.a ? one.b < two.b : one.a < two.a;
}
int main()
{
	int num = 1;
	while(~scanf("%d",&n) && n != 0)
	{
		mmset(dp,0);
		int len = 1;
		int a,b,c;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d %d %d",&a,&b,&c);
			addData(a,b,c,len);
		}
		sort(data + 1, data + len,cmp) ;
		int res = -1;
		for(int i = 1; i < len; i++)
		{
			dp[i] = data[i].h;
			for(int j = 1; j < i; j++)
			{
				if(data[j] < data[i])
				{
					dp[i] = max(dp[i], dp[j] + data[i].h);
				}
			}
			res = max(res,dp[i]);
		}
		printf("Case %d: maximum height = %d\n",num++,res);
	}
	
	
	
	
	return 0;
}
