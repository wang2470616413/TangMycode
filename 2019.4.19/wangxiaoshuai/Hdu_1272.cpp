#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1e5 + 5;
int father[N];
int mark[N];
void init(int a, int b)
{
	for(int i = a; i <= b; i++)
	{
		father[i] = i;
	}
	mmset(mark,0);
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
	int flag = 0;
	int a,b, num = 0,edges = 0;
	init(0,N - 3);
	while(~scanf("%d %d",&a,&b))
	{
		if(a == -1 && b == -1)
		{
			break;
		}
		if(a == 0 && b == 0)
		{
		
			if(flag == 0 && num == edges - 1 || num == 0)
			{
				printf("Yes\n");
			}
			else
			{
				printf("No\n");
			}
			flag = 0, edges = 0, num = 0;
			init(0,N - 3);
		}
		else 
		{
			if(mark[a] == 0)
			{
				edges++;
				mark[a] = 1;
			}
			if(mark[b] == 0)
			{
				edges++;
				mark[b] = 1;
			} 
			if(find(a) != find(b))
			{
				merge(a,b);
				num++;
			}
			else 
			{
				flag = 1;
			}
		}
	
	}

	
	return 0;
}
