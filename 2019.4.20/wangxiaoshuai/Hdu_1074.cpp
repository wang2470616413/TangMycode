#include<stdio.h>
#include<string>
#include<iostream>
#include<string.h>
#include<algorithm>
#define ll long long
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 15;
struct node
{
	string str;
	int a, b;
	node* p;
	node()
	{
		
	};
	node(string p_str, int p_a, int p_b)
	{
		str = p_str;
		a = p_a;
		b = p_b;
	};
};
struct node0
{
	int p;
	int index;
};
node data[N + 5];
node0 path[1 << (N + 1)];
int dp[1 << (N + 1)];
int cost[1 << (N + 1)];
int n; 
void printfPath(int p)
{
	if(p == 0)
	{
		return ;
	}
	else
	{
		printfPath(path[p].p);
		cout<<data[path[p].index].str<<endl; 
	}
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		cin>> n;
		mmset(cost,0);
		mmset(dp,0x3f);
		dp[0] = 0;
		for(int i = 0; i < n; i++)
		{
			cin>>data[i].str>>data[i].a>>data[i].b;
		}
		for(int state = 0; state <= (1 << n) - 1; state ++)
		{
			for(int i = 0; i < n; i ++)
			{
				if((state & (1 << i)) == 0)
				{
					int ncost = cost[state] + data[i].b;
					int nres = ncost - data[i].a <  0 ? 0 : ncost - data[i].a;
					int nstate = state | (1 << i);
					if(dp[nstate] > dp[state] + nres)
					{
						path[nstate].p = state;
						path[nstate].index = i;
						dp[nstate] = dp[state] + nres;
						cost[nstate] = ncost;
					}
				}
			}
		}
		printf("%d\n",dp[(1 << n) - 1]);
		printfPath((1 << n) - 1);
	}
	
	
	
	
	return 0;
} 
