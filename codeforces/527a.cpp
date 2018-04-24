#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a, b, counter =0, r;
    cin>>a>>b;
    while (b!=0)
    {
        r = a%b;
        counter += a/b;
        a=b;
        b=r; 
    }
    /**while (a > 0 && b > 0)
    {
        if (a >= b)
        {
            counter+=(a/b);
            a = a % b;
        }
        else
        {
            counter += (b / a);
            b = b % a;
        }           
    }**/
    cout<<counter;
}