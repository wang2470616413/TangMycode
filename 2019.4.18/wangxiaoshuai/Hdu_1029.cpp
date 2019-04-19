#include<string.h>
#include<stdio.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memeset(a,b,sizeof(a))
using namespace std;
const int N = 1e6 + 5;
int data[N];
int n;
int main()
{
	while(~scanf("%d",&n))
	{
		for(int i = 1; i <= n; i++)
		{
			scanf("%d",&data[i]);
		}
		sort(data + 1, data + 1 + n);
		printf("%d\n",data[(n + 1) / 2]);
	}
	return 0;
}
