#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s1;
	int t1=0 , t2=0;
	cin >> s1;
	int len = s1.length();
	for(int i = 0 ; i <= len ; i++)
	{
		if(s1[i] >= 'a' && s1[i] <= 'z')
		{
			t1++;
		}
		else if(s1[i] >= 'A' && s1[i] <= 'Z')
		{
			t2++;
		}
	}
//	printf("t1 = %d t2 = %d\n" , t1 , t2);
	if(t1>=t2)
	{
		transform(s1.begin() , s1.end(),s1.begin(),::tolower);
	}
	else
	{
		transform(s1.begin() , s1.end() , s1.begin() , :: toupper);
	}
	cout << s1<<endl;
	return 0;
}
