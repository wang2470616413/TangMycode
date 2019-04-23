#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 105;
int data[N][N], dis[N], mark[N];
int n , m,res ;
void init(int n)
{
	mmset(data,0x3f);
	for(int i = 0; i <= n; i++)
	{
		data[i][i] = 0;
	}
	res = 0;
}
int prim(int s)
{
	int num = 0;
	mmset(dis,0x3f);
	mmset(mark,0);
	dis[s] = 0, mark[s] = 1;
	for(int i = 1; i <= n; i++)
	{
		dis[i] = data[s][i];
	}
	for(int i = 1; i < n; i++)
	{
		int min1 = 0x3f3f3f3f;
		int u = -1;
		for(int j = 1; j <= n; j++)if(mark[j] == 0 && min1 > dis[j])
		{
			min1 = dis[j];
			u = j;
		}
		if(u != -1)
		{
			num++;
			mark[u] = 1;
			res += min1;
			for(int j = 1; j <= n;j++)if(mark[j] == 0 && dis[j] > data[u][j])
			{
				dis[j] = data[u][j];
			}
		}
	}
	return num;
}
int main()
{
	while(~scanf("%d %d",&m,&n) && m != 0)
	{
		init(n);
		int a,b,c;
		for(int i = 1; i <= m; i++)
		{
			scanf("%d %d %d",&a,&b,&c);
			data[a][b] = data[b][a] = min(c,data[a][b]);
		}
		int num = prim(1);
		if(num != n-1)
		{
			printf("?\n");
		}
		else
		{
			printf("%d\n",res);
		}
	}
	
	
	
	return 0;
}
