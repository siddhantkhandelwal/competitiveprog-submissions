#include<iostream>
using namespace std;
int main()
{
    int n,temp,taxi=0;
    int t[]={0,0,0,0};
    cin>>n;
    while(n--)
    {
        cin>>temp;
        t[temp-1]++;
    }
    taxi=t[3]+t[2]+(t[1]/2);
    t[0]-=t[2];
    t[1]=t[1]%2;
    if(t[1])
    {
        taxi++;
        t[0]-=2;
    }
    while(t[0]>0)
    {
        taxi++;
        t[0]-=4;
    }
    cout<<taxi;
    return 0;
}
