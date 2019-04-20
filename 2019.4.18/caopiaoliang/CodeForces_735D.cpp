#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long ll;//根据需要改成unsigned long long

const int times=20;

ll mul(ll x,ll y,ll MOD){
    x=x%MOD,y=y%MOD;
    return ((x*y-(ll)(((long double)x*y+0.5)/MOD)*MOD)%MOD+MOD)%MOD;
}

ll Random(ll n){
    return ((double)rand()/RAND_MAX*n+0.5);
}

ll pw(ll a,ll b,ll MOD){
    ll ans=1;
    while(b){
        if(b&1) ans=mul(ans,a,MOD);
        b/=2;
        a=mul(a,a,MOD);
    }
    return ans;
}

bool witness(ll a,ll n){
    ll tmp=n-1;
    int j=0;
    while(tmp%2==0){
        tmp/=2;
        ++j;
    }
    ll x=pw(a,tmp,n);
    if(x==1 || x==n-1) return true;
    while(j--){
        x=mul(x,x,n);
        if(x==n-1) return true;
    }
    return false;
}

bool miller(ll n){
    if(n==2) return true;
    if(n<2 || n%2==0) return false;
    for(int i=1;i<=times;++i){
        ll a=Random(n-2)+1;
        if(!witness(a,n)) return false;
    }
    return true;
}
int main()
{
	int n;
	scanf("%d" , &n);
	if(miller(n))
	{
		printf("1\n");
	} 
	else if(n%2==0)
	{
		printf("2\n");
	}
	else if(n%2==1)
	{
		if(miller(n-2))
		{
			printf("2\n");
		}
		else
		{
			printf("3\n");
		}
	}
	
	return 0;
 } 