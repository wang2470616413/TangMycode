#include <bits/stdc++.h> 
using namespace std;
map<int , string>M;
struct node
{
	string s1 ;
	string s2;
}a[200];
int main()
{
	int n , t = 1;
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a[i].s1 >> a[i].s2;
		if(a[i].s2[0] == 'r')
		{
			M[t++] = a[i].s1;
		}
	}
	for(int i = 1 ; i <= n ; i++)
	{
		if(a[i].s2[0] == 'w'||(a[i].s2[0] == 'c'&&a[i].s2[1] == 'h'))
		{
			M[t++] = a[i].s1;
		}
	}
	for(int i = 1 ; i <= n ; i++)
	{
		if(a[i].s2[0] == 'm')
		{
			M[t++] = a[i].s1;
		}
	}
	for(int i = 1 ; i <= n ; i++)
	{
		if(a[i].s2[0] == 'c'&&a[i].s2[1] == 'a')
		{
			M[t++] = a[i].s1;
		}
	}
	for(int i = 1 ; i < t ; i++)
	{
		cout <<M[i]<<endl;
	}
	return 0;
}
