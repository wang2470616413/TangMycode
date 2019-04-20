#include <bits/stdc++.h>
	using namespace std;
	int main()
	{
		char num[120];
		char s1[120] , s2[120] , s3[120] , s4[120];
		strcpy(s1 ,"127" );
		strcpy(s2 ,"32767" );
		strcpy(s3 ,"2147483647");
		strcpy(s4 ,"9223372036854775807" );
		cin >> num;
		int len = strlen(num);
		if(len < 3)
		{
			printf("byte\n");
		}
		else if(len == 3)
		{
			if(strcmp(num ,s1) <= 0)
			{
				printf("byte\n");
			}
			else
			{
				printf("short\n");
			}
		}
		else if(len < 5 && len > 3)
		{
			printf("short\n");
		}
		else if(len == 5)
		{
			if(strcmp(num ,s2) <= 0)
			{
				printf("short\n");
			}
			else
			{
				printf("int\n");
			}
		}
		else if(len < 10 && len > 5)
		{
			printf("int\n");
		}
		else if (len == 10)
		{
			if(strcmp(num ,s3) <= 0)
			{
				printf("int\n");
			}
			else
			{
				printf("long\n");
			}
		}
		else if(len > 10 && len < 19)
		{
			printf("long\n");
		}
		else if(len == 19)
		{
			if(strcmp(num ,s4) <= 0)
			{
				printf("long\n");
			}
			else
			{
				printf("BigInteger\n");
			}
		}
		else if(len > 19)
		{
			printf("BigInteger\n");
		}
	
		return 0;
	 } 