#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int money[1001];
    cin>>n;
    int i;
    for(i=0;i<n;++i)
        cin>>money[i];
    if(n==1 && money[0]==1)
        cout<<"-1";
    else
    {
    sort(&money[0],&money[n]);
    if(binary_search(&money[0],&money[n], 1))
        cout<<"-1";
    else
        cout<<"1";
    }
    return 0;
}