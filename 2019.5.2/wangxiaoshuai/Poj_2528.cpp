#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long
#define mmset(a,b) memset(a,b,sizeof(a))
#define  lson l,m,rt << 1
#define rson m+1, r,rt <<1|1
using namespace std;
const int N = 2e5 + 5;
int col[N << 2],mark[N << 2];
int map1[N],data[N][2];
int aux[N];
int res = 0;
void PushDown(int l, int r ,int rt)
{
	if(col[rt] != 0)
	{
		col[rt << 1] = col[rt];
		col[rt<<1|1] = col[rt];
		col[rt] = 0;
	}
}
void Update(int L, int R, int v, int l,int r, int rt)
{
	if(l >= L && r <= R)
	{
		col[rt] = v;
		return;
	}
	else
	{
		PushDown(l,r,rt);
		int m = (l + r) >> 1;
		if(L <= m)
		{
			Update(L,R,v,lson);
		}
		if(R >= m + 1)
		{
			Update(L,R,v,rson);
		}
	}
}
void query(int L, int R, int l, int r, int rt)
{
	if(col[rt] != 0)
	{
		if(mark[col[rt]] == 0)
		{
			mark[col[rt]] = 1;
			res++;
		}
		return ;
	}
	if(l == r) 
	{
		return ;
	}
	PushDown(l,r,rt);
	int m = (l + r) >> 1;
	if(L <= m)
	{
		query(L,R,lson);
	}
	if(R >= m + 1)
	{
		query(L,R,rson);
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--) 
	{
		int n;
		scanf("%d",&n);
		int a,b;
		mmset(col,0) ;
		mmset(mark,0);
		for(int i = 1; i <= 2 * n; i++)
		{
			scanf("%d %d",&map1[i],&map1[i] + 1) ;
			i++;
			data[i / 2][0] = map1[i - 1];
			data[i / 2][1] = map1[i];
			
		}
		sort(map1 + 1, map1 + 2 * n + 1);
		int len = 1;
		for(int i = 1; i < 2 * n; i++)if(map1[i] != map1[i + 1])
		{
			map1[len] = map1[i];
			len++;
		}
		map1[len] = map1[2 * n];
		int len1 = 2;
		aux[1] = 1;
		for(int i = 2; i <= len; i++)
		{
			if(map1[i] - map1[i - 1] > 1)
			{
				aux[len1] = map1[i-1];
				len1++;
				aux[len1] = map1[i];
				len1++;
			}
			else
			{
				aux[len1] = map1[i];
				len1++;
			}
		}
		for(int i = 1; i <= n; i++)
		{
			int a = lower_bound(aux + 1, aux + len1,data[i][0]) - aux ;
			int b = lower_bound(aux + 1, aux  + len1,data[i][1]) - aux;
			Update(a,b,i,1,len1 - 1,1);
		}
		res = 0;
		
		mmset(mark,0);
		query(1,len1 - 1,1,len1 - 1,1) ;
		printf("%d\n",res);
		
		
		

	}
	
	
	return 0;
} 
