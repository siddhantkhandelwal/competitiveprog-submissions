#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void solve()
{
    int a, b;
    cin >> a >> b;
    int zero = a;
    int one = b;
    vector<char> v(a + b, ' ');
    forn(i, a + b)
    {
        cin >> v[i];
    }
    forn(i, a + b)
    {
        if (v[i] == '0')
        {
            zero--;
        }
        else if (v[i] == '1')
        {
            one--;
        }
    }
    int start, end;
    for (int i = 0; i < a + b; i++)
    {
        if (v[i] == '?')
        {
            start = i;
            break;
        }
    }
    for (int i = a + b - 1; i >= 0; i--)
    {
        if (v[i] == '?')
        {
            end = i;
            break;
        }
    }
    int k = 0;
    int l = a + b - 1;
    while (k < start && l > end)
    {
        if (v[k] != v[l])
        {
            cout << "-1" << ln;
            return;
        }
        k++;
        l--;
    }
    for (int i = start; i <= end; i++)
    {
        if (v[i] != '?')
        {
            continue;
        }
        if (v[a + b - i - 1] == '?')
        {
            if (zero == 0 && one == 0)
            {
                cout << "-1" << ln;
                return;
            }
            if (zero >= one)
            {
                if (i == a + b - i - 1)
                {
                    zero--;
                    v[i] = '0';
                }
                if (zero < 2)
                {
                    cout << "-1" << ln;
                    return;
                }
                zero -= 2;
                v[i] = '0';
                v[a + b - i - 1] == '0';
            }
            else
            {
                if (i == a + b - i - 1)
                {
                    one--;
                    v[i] = '1';
                }
                if (one < 2)
                {
                    cout << "-1" << ln;
                    return;
                }
                one -= 2;
                v[i] = '1';
                v[a + b - i - 1] == '1';
            }
        }
        else
        {
            if (v[a + b - i - 1] == '0')
            {
                if (zero)
                {
                    v[i] = '0';
                    zero--;
                }
                else
                {
                    cout << "-1" << ln;
                    return;
                }
            }
            else if (v[a + b - i - 1] == '1')
            {
                if (one)
                {
                    v[i] = '1';
                    one--;
                }
                else
                {
                    cout << "-1" << ln;
                    return;
                }
            }
        }
    }
    forn(i, a + b)
    {
        if (v[i] != v[a + b - i - 1])
        {
            cout << "-1" << ln;
            return;
        }
    }
    forn(i, a + b)
    {
        cout << v[i];
    }
    cout << ln;
}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}