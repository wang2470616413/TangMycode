#include<string>
#include<string.h> 
#include<iostream>
#include<algorithm>
#define ll long long
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const string b = "127";
const string s = "32767";
const string i = "2147483647";
const string l = "9223372036854775807";
int main()
{
	string str;
	cin>>str;
	if(str.length() < b.length() || (str.length() == b.length() && strcmp(str.c_str(),b.c_str()) <= 0))
	{
		cout<<"byte"<<endl;
	}
	else if(str.length() < s.length() || (str.length() == s.length() && strcmp(str.c_str(),s.c_str()) <= 0))
	{
		cout<<"short"<<endl;
	}
	else if(str.length() < i.length() || (str.length() == i.length() && strcmp(str.c_str(),i.c_str()) <= 0))
	{
		cout<<"int"<<endl;
	}
	else if(str.length() < l.length() || (str.length() == l.length() && strcmp(str.c_str(),l.c_str()) <= 0))
	{
		cout<<"long"<<endl;
	}
	else
	{
		cout<<"BigInteger"<<endl;
	}
	return 0;
}

