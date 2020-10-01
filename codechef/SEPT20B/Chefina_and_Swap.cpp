#include <bits/stdc++.h>

#define ll long long int

using namespace std;

ll ncrmodpdp(ll n, ll r, ll p)
{
    ll c[r + 1];
    memset(c, 0, sizeof(c));
    c[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = min(i, r); j > 0; j--)
        {
            c[j] = (c[j] + c[j - 1]) % p;
        }
    }
    return c[r];
}

ll ncrmodplucas(ll n, ll r, ll p)
{
    if (r == 0)
        return 1;

    ll ni = n % p;
    ll ri = r % p;
    return (ncrmodplucas(n / p, r / p, p) * ncrmodpdp(ni, ri, p)) % p;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    ll t0 = t;
    ll k = 0;
    vector<ll> res(t0);
    while (t--)
    {
        ll n;
        cin >> n;
        if ((n * (n + 1) / 2) % 2 == 1)
        {
            res[k] = 0;
        }
        else
        {
            ll sum = 0, c = 0;
            ll half = n * (n + 1) / 4;
            for (ll i = n; i >= 1; i--)
            {
                sum = sum + i;
                c++;
                if (sum == half)
                {
                    res[k] = ncrmodplucas(n - c, 2, 1000000007) + ncrmodplucas(c, 2, 1000000007) + c;
                    break;
                }
                else if (sum > half)
                {
                    res[k] = c;
                    break;
                }
            }
        }
        k++;
    }
    for (ll i = 0; i < t0; i++)
    {
        cout << res[i] << "\n";
    }
    return 0;
}