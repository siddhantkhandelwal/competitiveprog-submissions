#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, n;
    cin>>t>>n;
    long long int l[n],s=0;
    for(int i=0;i<t;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin>>l[j];
            s+=l[j];
        }
        cout<<s*s;
    }
    return 0;
}
