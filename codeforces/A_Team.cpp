#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    int res = 0;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        res += ((a ? 1 : 0) + (b ? 1 : 0) + (c ? 1 : 0)) >= 2 ? 1 : 0;
    }
    cout << res << "\n";
    return 0;
}