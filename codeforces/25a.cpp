#include<iostream>
using namespace std;
int main()
{
    int n, no[100],counter=0;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>no[i];
        if(no[i]%2==0)
        counter++;
    }   
    if(counter==n-1)
    {
        for(int i=0;i<n;++i)
        {
            if(no[i]%2!=0)
            {
                cout<<i+1;
                break;
            }
        }   
    }
    else
    {
        for(int i=0;i<n;++i)
        {
            if(no[i]%2==0)
            {
                cout<<i+1;
                break;
            }
        }
    }
    return 0;
}