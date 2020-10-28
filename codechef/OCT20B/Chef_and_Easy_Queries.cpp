#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll carry = 0;
        ll i = 0;
        bool flag = false;
        while (i < n)
        {
            i++;
            ll temp = 0;
            cin >> temp;
            if (temp + carry < k)
            {
                flag = true;
                cout << i << endl;
                break;
            }
            if (temp + carry - k > 0)
            {
                carry = temp + carry - k;
            }
            else
            {
                carry = 0;
            }
        }
        if (!flag)
        {
            cout << n + (ll)(carry / k) + 1 << endl;
        }
    }
    return 0;
}