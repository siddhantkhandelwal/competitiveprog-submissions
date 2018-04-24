#include<iostream>
using namespace std;
int main()
{
    int n,count=0;
    cin>>n;
    char arr[100];
    while(n)
    {
        count=0;
        char arr[101];
        cin>>arr;
        for(int i=0;arr[i]!='\0';++i)
        count++;
        if(count>10)
        cout<<arr[0]<<count-2<<arr[count-1]<<endl;
        else
        cout<<arr<<endl;
        n--;
    }
    return 0;
}