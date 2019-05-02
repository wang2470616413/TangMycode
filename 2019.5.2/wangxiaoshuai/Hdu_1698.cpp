#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long
#define mmset(a,b) memset(a,b,sizeof(a))
#define lson l,m,rt<<1
#define rson m + 1, r,rt<<1|1
using namespace std;
const int N = 1e5 + 5;
int sum[N << 2], mark[N << 2];
int PushUp(int rt)
{
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
int PushDown(int len, int rt) 
{
	if(mark[rt] > 0)
	{
		sum[rt<<1 | 1] = (len >> 1) * mark[rt];
		sum[rt << 1] = ((len + 1) >> 1) * mark[rt];
		//sum[rt<<1] = (len - (len>>1)) * mark[rt];
	//	sum[rt<<1|1] = (len>>1) * mark[rt];
		mark[rt << 1] = mark[rt];
		mark[rt << 1 | 1] = mark[rt];
		mark[rt] = 0;
	} 
}
int Build(int l, int r, int rt)
{
	if(l == r)
	{
		sum[rt] = 1;
	}
	else
	{
		int m = (l + r) >> 1;
		Build(lson); 
		Build(rson);
		PushUp(rt);
	}
}
int update(int L,int R, int num, int l, int r, int rt)
{
	if(L <= l && R >= r)
	{
		sum[rt] = (r - l + 1) * num;
		mark[rt] = num;
	}
	else
	{
		int m = (l + r) >> 1;
		PushDown(r - l + 1, rt);
		if(L <= m) 
		{
			update(L,R,num,lson);
		}
		if(R > m)
		{
			update(L,R,num,rson);
		}
		PushUp(rt);
	}
}
int query(int L, int R, int l, int r, int rt) 
{
	if(L <= l && R >= r)
	{
		return sum[rt];
	}
	else
	{
		int m = (l + r) >> 1;
		PushDown(r - l + 1, rt);
		int res = 0;
		if(L <= m)
		{
			res += query(L,R,lson);
		}
		if(R > m)
		{
			res += query(L,R,rson);
		}
		return res;
	}
}
int main()
{
	int T;
	int num = 1;
	scanf("%d",&T);
	while(T--)
	{
		mmset(mark,0);
		int n, m;
		scanf("%d",&n);
		Build(1,n,1);
		scanf("%d",&m);
		int a,b,c;
		for(int i = 1; i <= m; i++)
		{
			scanf("%d %d %d",&a,&b,&c);
			update(a,b,c,1,n,1);
		}
		printf("Case %d: The total value of the hook is %d.\n",num++,query(1,n,1,n,1));
	}
	
	
	
	return 0;
} 
