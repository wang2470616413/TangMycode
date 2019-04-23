#include<stdio.h>
#include<string.h>
#include<map>
#include<algorithm>
#define ll long long
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1e5 + 5;
int father[N], rootNum[N], n, res;
map <int,int> map1;
int addMap(int num,int& len) 
{
	if(map1.count(num) == 0)
	{
		map1[num] = len++;
		return len -1; 
	}
	return map1[num];
}

void init(int a,int b)
{
	for(int i = a; i <= b; i++)
	{
		father[i] = i;
		rootNum[i] = 1;
	}
	map1.clear(); 
}
int find(int x)
{
	return father[x] = father[x] == x ? x : find(father[x]);
}
void merge(int x,int y)
{
	int fx = find(x);
	int fy = find(y);
	if(fx != fy)
	{
		father[fx] = fy;
		rootNum[fy] += rootNum[fx];
		res = max(res,rootNum[fy]);
	}
}
int main()
{
	while(~scanf("%d",&n))
	{
		init(0, 1e5 + 2);
		int len = 1;
		res =  0;
		for(int i = 1; i <= n; i++)
		{
			int a, b;
			scanf("%d %d",&a,&b);
			int x = addMap(a,len);
			int y = addMap(b,len);
			merge(x,y);
		}
		res = n == 0 ? 1: res;
		printf("%d\n",res);
	}

	
	return 0;
}
