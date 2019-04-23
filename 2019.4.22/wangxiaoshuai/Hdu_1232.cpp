#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long
#define mmset(a,b) memset(a,b,sizeof(a)) 
const int N = 1e3 + 5;
int num , n, m;
int father[N];
void init(int a, int b)
{
	for(int  i = a; i <= b; i++)
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
	while(~scanf("%d",&n) && n != 0)
	{
		scanf("%d",&m);
		init(0, n + 3);
		num = 0;
		int a,b;
		for(int i = 1; i <= m; i ++)
		{
			scanf("%d %d",&a, &b);
			int fx = find(a);
			int fy = find(b);
			if(fx != fy)
			{
				merge(fx,fy);
				num++;
			}
		}

		printf("%d\n",n - 1 - num);
	}
	
	
	
	
	
	return 0;
} 
