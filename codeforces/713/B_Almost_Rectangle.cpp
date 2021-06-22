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
    int n;
    cin >> n;
    int ar1 = -1;
    int ac1 = -1;
    int ar2 = -1;
    int ac2 = -1;
    int ar3 = -1;
    int ac3 = -1;
    int ar4 = -1;
    int ac4 = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char t;
            cin >> t;
            if (t == '*')
            {
                if (ar1 == -1)
                {
                    ar1 = i;
                    ac1 = j;
                }
                else if (ar2 == -1)
                {
                    ar2 = i;
                    ac2 = j;
                }
            }
        }
    }
    if (ar1 == ar2)
    {
        // same row
        if (ar1 == 0)
        {
            ar3 = 1;
            ar4 = 1;
            ac3 = ac1;
            ac4 = ac2;
        }
        else if (ar1 == n - 1)
        {
            ar3 = ar1 - 1;
            ar4 = ar1 - 1;
            ac3 = ac1;
            ac4 = ac2;
        }
        else
        {
            ar3 = ar1 - 1;
            ar4 = ar1 - 1;
            ac3 = ac1;
            ac4 = ac2;
        }
    }
    else if (ac1 == ac2)
    {
        // same column
        if (ac1 == 0)
        {
            ac3 = 1;
            ac4 = 1;
            ar3 = ar1;
            ar4 = ar2;
        }
        else if (ac1 == n - 1)
        {
            ac3 = ac1 - 1;
            ac4 = ac1 - 1;
            ar3 = ar1;
            ar4 = ar2;
        }
        else
        {
            ac3 = ac1 - 1;
            ac4 = ac1 - 1;
            ar3 = ar1;
            ar4 = ar2;
        }
    }
    else
    {
        ar3 = ar1;
        ac3 = ac2;
        ar4 = ar2;
        ac4 = ac1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == ar1 && j == ac1)
            {
                cout << "*";
            }
            else if (i == ar2 && j == ac2)
            {
                cout << "*";
            }
            else if (i == ar3 && j == ac3)
            {
                cout << "*";
            }
            else if (i == ar4 && j == ac4)
            {
                cout << "*";
            }
            else
            {
                cout << ".";
            }
        }
        cout << ln;
    }
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