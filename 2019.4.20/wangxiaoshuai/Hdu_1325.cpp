#include<stdio.h>
#include<string.h>
#include<map>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1e6 + 5;
map <int,int> map1;
int father[N];
int book[N];
int addMap(int num, int& len)
{
	if(map1.count(num) == 0)
	{
		map1[num] = len++;
		return len - 1;
	}
	return map1[num];
}
void init(int a, int b)
{
	for(int i = a; i <= b; i++)
	{
		father[i] = i;
	}
	mmset(book,0);
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
bool is(int n)
{
	for(int i = 0; i <= n; i++)
	{
		find(i);
	}
	int num = father[0];
	for(int i = 0; i <= n; i++)
	{
		if(father[i] != num)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int a,b;
	int edges = 0, num = 0, len = 0, flag = 0;
	int mark = 1;
	init(0,N - 3);
	while(scanf("%d %d",&a,&b) != EOF)
	{
		if(a < 0 && b < 0)
		{
			break;
		}
		if(a == 0 && b == 0)
		{
			len = map1.size();
			if((flag == 0 && num == len - 1 && is(len - 1)) || (num == 0 && len == 0))
			{
				printf("Case %d is a tree.\n",mark++);
			}
			else
			{
				printf("Case %d is not a tree.\n",mark++);
			}
			edges = num = len = flag = 0;
			map1.clear();
			init(0,N-3);
		}
		else
		{
			int x = addMap(a,len);
			int y = addMap(b,len);
			int fx = find(x);
			int fy = find(y);
			book[y]++;
			if(book[y] >= 2)
			{
				flag = 1;
			}
			if(fx != fy)
			{
				num++;
				merge(x,y);
			}
			else
			{
				flag = 1;
			}
		}
	}
	
	
	
	return 0;
}
