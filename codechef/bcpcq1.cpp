#include<bits/stdc++.h>
using namespace std;
int calc (long long int k, long long int s=0, long long int j=1)
{
    s=(j*(j+1))/2;
    if(s<k)
    {
    j++;
    return calc(k, s, j);
    }
    return j;

}
int main()
{
    long long int t, w, k, i;
    cin>>t;
    for(i=0;i<t;++i)
    {
        cin>>w>>k;
        int res = calc(w-k);
        cout<<res<<endl;
    }
}