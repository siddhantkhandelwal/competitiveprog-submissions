#include<iostream>
#include<math.h>
using namespace std;
int main()
{
long long int n,m,a,n1,m1;
cin>>n>>m>>a;
n1=n/a;
if(n%a)
n1++;
m1=m/a;
if(m%a)
m1++;
cout<<n1*m1;
return 0;
}
