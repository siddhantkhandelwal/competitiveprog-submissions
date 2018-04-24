#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, n;
    int l, w;
    cin>>t>>n;
    for(int i=0;i<t;++i)
        {
            for(int j=0;j<n;++j)
            {
            cin>>l>>w;
            if((l*w)<=(3.14*0.25*((l*l)+(w*w))))
            cout<<"no"<<endl;
            else
            cout<<"yes"<<endl;
            }            
        }
    return 0;
}