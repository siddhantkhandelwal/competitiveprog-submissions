#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define test  \
    ll t;     \
    cin >> t; \
    while (t--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

/*/----------------------------- Code begins -----------------------------/*/

int main()
{
    fio;
    test
    {
        ll n, x, y, p = 0, q = 0, i;
        cin >> n;
        string a, b;
        while (n--)
        {
            cin >> a >> b;
            x = 0;
            y = 0;
            for (i = 0; i < a.length(); i++)
                x += a[i] - '0';
            for (i = 0; i < b.length(); i++)
                y += b[i] - '0';
            if (x > y)
                p++;
            else if (x < y)
                q++;
            else
            {
                p++;
                q++;
            }
        }
        if (p > q)
            cout << "0 " << p;
        else if (p < q)
            cout << "1 " << q;
        else
            cout << "2 " << p;
        cout << "\n";
    }
    return 0;
}