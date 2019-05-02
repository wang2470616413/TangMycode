#include<stdio.h> 
#include<string.h>
#include<algorithm>
#define ll long long
#define mmset(a,b) memset(a,b,sizeof(a))
#define lson l,m,rt<<1
#define rson m + 1, r, rt<<1|1
const int N = 5e4 + 5;
int sum[N << 2], data[N];
void PushUp(int rt)
{
	sum[rt] = sum[rt<< 1] + sum[rt<<1|1];
}
void Build(int l, int r, int rt)
{
	if(l == r)
	{
		sum[rt] = data[l];
	}
	else
	{
		int m = (l +r) >> 1;
		Build(lson);
		Build(rson);
		PushUp(rt);
	}
}
void update(int P, int num, int l , int r, int rt) 
{
	if(l == r)
	{
		sum[rt] += num;
	}
	else
	{
		int m = (l + r) >> 1;
		if(P <= m) 
		{
			update(P,num,lson);
		} 
		else
		{
			update(P,num,rson);
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
		int res = 0;
		if(L <= m)
		{
			res += query(L,R,lson);
		}
		if(R > m)
		{
			res += query(L,R,rson) ;
		}
		return res;
	}
}
int main()
{
	int num = 1;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d",&data[i]);
		}
		Build(1,n,1);
		char opea[105];
		int a,b;
		printf("Case %d:\n",num++);
		while(scanf("%s",opea+1))
		{
			if(opea[1] == 'E')
			{
				break;
			}
			else
			{
				scanf("%d %d",&a,&b);
				if(opea[1] == 'A')
				{
					update(a,b,1,n,1);
				}
				else if(opea[1] == 'S')
				{
					update(a,-b,1,n,1);
				}
				else
				{
					int res = query(a,b,1,n,1);
					printf("%d\n",res);
				}
			}
		}
	}
	
	
	
	return 0;
}
