#include<bits/stdc++.h>
using namespace std;
int powers(long long int n, int x = 1, int s=0)
{
    if(n>(5^x))
    {
    s+=n/(5^x);
    x++;
    return (powers((n/(5^x)),x,s));
    }
    else
    return s;
}
int main()
{
    long long int t, n, i;
    for (i = 0; i<t; ++i)
    {
        cin>>n;
        cout<<powers(n);
    }   
    return 0;
}