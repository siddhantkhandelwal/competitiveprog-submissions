#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, tim=240,counter=0;
    cin>>n>>k;
    tim-=k;
    for(int i=1;i<=n;++i)
    {
        tim=tim-(5*i);
        if(tim>=0)
        counter++;
        else
        break;
    }
    cout<<counter;
}