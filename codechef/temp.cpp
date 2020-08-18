#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll power(ll x, ll y, ll d)
{
    x = x % d;
    int temp;
    if (y == 0)
        return 1;
    temp = power(x, y / 2, d);
    if (y % 2 == 0)
        return (temp * temp) % d;
    else
        return (x * (temp * temp) % d) % d;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll val[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> val[i];
        }
        for (ll i = 0; i < n; i++)
        {
            cout << power(2, n - i, 1000000007) << " ";
        }
        cout << endl;
    }
    return 0;
}