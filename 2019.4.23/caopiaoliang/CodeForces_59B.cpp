#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n , x , sum = 0,maxn=200;
	scanf("%d" , &n);
	while(n--)
	{
		scanf("%d" , &x);
		sum+=x;
		if(x%2==1&&x < maxn)maxn = x; 
	 } 
	 if(sum%2==1)cout <<sum<<endl;
	 else
	 {
	 	if(maxn==200)cout<<"0"<<endl;
	 	else cout <<sum-maxn<<endl;
	 }
	return 0;
}
