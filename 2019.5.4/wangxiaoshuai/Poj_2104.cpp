#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long a[10];
    for (int i = 1; i < 10; i++) 
        if (i&1) a[i] = i;
        else a[i] = rand();
    printf("哈哈%lld\n", a[1]);
    vector<int> v;
    
    return 0;
}