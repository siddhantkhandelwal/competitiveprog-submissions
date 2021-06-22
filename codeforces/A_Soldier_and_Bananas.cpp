#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    int n, k, w;
    ll sum = 0;

    cin >> k >> n >> w;
    sum = k * (w * (w + 1)) / 2;
    cout << (sum <= n ? 0 : sum - n) << "\n";
    return 0;
}