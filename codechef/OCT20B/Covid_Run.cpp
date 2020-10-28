#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k, x, y;
        cin >> n >> k >> x >> y;
        if (x == y)
        {
            cout << "YES" << endl;
            continue;
        }
        ll loc = x;
        while (true)
        {
            loc = (loc + k) % n;
            if (loc == y)
            {
                cout << "YES" << endl;
                break;
            }
            else if (loc == x)
            {
                cout << "NO" << endl;
                break;
            }
        }
    }
    return 0;
}