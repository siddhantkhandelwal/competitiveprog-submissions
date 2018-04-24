#include<bits/stdc++.h>
using namespace std;
int main()
{
long double l, a[1000], maxdiff;
int n;
cin>>n>>l;
for(int i=0;i<n;++i)
cin>>a[i];
sort(a, a+n);
maxdiff=a[1]-a[0];
cout<<fixed<<setprecision(10);
for(int i=1; i<=(n-1);++i)
{
if(maxdiff<(a[i]-a[i-1]))
maxdiff= a[i]-a[i-1];
}
maxdiff=maxdiff/2;
if (maxdiff<a[0])
maxdiff=a[0];
if(maxdiff<(l-a[n-1]))
maxdiff=l-a[n-1];
cout<<maxdiff;
return 0;
} 
