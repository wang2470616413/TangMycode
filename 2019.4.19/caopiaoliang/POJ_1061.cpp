#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;
ll ExEculid(ll a , ll b , ll &x , ll &y)
{
	if(b == 0)
	{
		y = 0 ; x = 1;
		return a;
	}
	
	ll tx , ty;
	ll d = ExEculid(b , a%b ,tx , ty);
	x = ty;
	y = tx - ( a/b )* ty;
	return d;
 }
int main()
{
	ll A , B , K;
	ll x , y , m , n , l , xx , yy;
	scanf("%lld %lld %lld %lld %lld" , &x , &y , &m , &n , &l);
	A = n-m;
	B = l;
	K = x-y;
	ll ans = ExEculid(A , B , xx , yy);
	if(K % ans != 0)
	{
		printf("Impossible\n");
	}
	else
	{
		xx = xx * K / ans;
		ll t = B / ans;
		ll op = (xx%t + t) % t;
		printf("%lld\n" , op);
	}
	return 0;
}
