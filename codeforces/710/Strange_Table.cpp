#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll x;
        int n, m;
        cin >> n >> m >> x;
        // ll idy = (x - 1) / n;
        // ll idx = n - (((x - 1) / n + 1) * n - 1 - (x - 1)) - 1;
        cout << (n - (((x - 1) / n + 1) * n - 1 - (x - 1)) - 1) * m + ((x - 1) / n) + 1 << "\n";
    }

    return 0;
}