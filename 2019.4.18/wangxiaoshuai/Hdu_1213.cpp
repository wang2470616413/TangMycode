#include<string.h>
#include<stdio.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1005;
int father[N];
int n,m;
int mark[N];
void init(int a, int b)
{
	for(int i = a; i <= b; i++)
	{
		father[i] = i;
	} 
}
int find(int x)
{
	return father[x] = father[x] == x ? x : find(father[x]);
}
void merge(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	if(fx != fy)
	{
		father[fx] = fy;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		mmset(mark,0);
		init(0,n + 1);
		int a, b;
		for(int i = 1; i <= m; i++) 
		{
			scanf("%d %d",&a,&b);
			if(find(a) != find(b))
			{
				merge(a,b);
			}
		}
		int res = 0;
		for(int i = 1; i <= n; i++)
		{
			find(i);
			if(mark[father[i]] == 0)
			{
				res++;
				mark[father[i]] = 1;
			}
		}
		printf("%d\n",res);
	}
	return 0;
} 

