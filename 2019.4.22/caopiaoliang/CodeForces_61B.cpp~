#include <bits/stdc++.h>
using namespace std;
string change(string a)
{
	string op;
	int len = a.length();
	int t = 0;
	for(int i = 0 ; i < len ; i++)
	{
		if(a[i] <='z' && a[i] >= 'a')
		op[t++] += a[i];
	}
	return op;
}
int main() 
{
	int n , len , t;
	string s1 , s2 , s3 , x1 , x2 , x3;
	string ans , ans1;
	cin >> s1 >> s2 >> s3;
	transform(s1.begin(),s1.end(),s1.begin(),::tolower);
	transform(s2.begin(),s2.end(),s2.begin(),::tolower);
	transform(s3.begin(),s3.end(),s3.begin(),::tolower);
	len = s1.length();
	for(int i = 0 ; i < len ; i++)
	{
		if(s1[i] <='z' && s1[i] >= 'a')
		{
			x1 += s1[i];
		}
	}	
	len = s2.length();
	for(int i = 0 ; i < len ; i++)
	{
		if(s2[i] <='z' && s2[i] >= 'a')
		{
			x2 += s2[i];
		}
	}	
	len = s3.length();
	for(int i = 0 ; i < len ; i++)
	{
		if(s3[i] <='z' && s3[i] >= 'a')
		{
			x3 += s3[i];
		}
	}	
	scanf("%d" , &n);
	while(n--)
	{
		cin >> ans;
		ans1 = "";
		len = ans.length();
		transform(ans.begin(),ans.end(),ans.begin(),::tolower);
		for(int i = 0 ; i < len ; i++)
		{
			if(ans[i] <='z' && ans[i] >= 'a')
			{
				ans1 += ans[i];
			}
		}	
		if(ans1 == x1+x2+x3 || ans1 == x1+x3+x2 || ans1 == x2+x1+x3 || ans1 == x2+x3+x1 || ans1 == x3+x1+x2||ans1 == x3+x2+x1)
		{
			printf("ACC\n");
		}
		else
		{
			printf("WA\n");
		}
	}
	return 0;
}
