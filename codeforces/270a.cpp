#include<iostream>
using namespace std;
int main()
{
int t;
cin>>t;
int a[180];
for(int i=0;i<t;++i)
{
    cin>>a[i];
    if((360%(180-a[i]))==0)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
}
}