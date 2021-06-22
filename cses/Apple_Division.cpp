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
#define pub push_back
#define pob pop_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void helper(v64 &apples, v64 temp, int id, ll appleSum, ll &minD)
{
    if (id >= apples.size())
    {
        ll sum = accumulate(all(temp), 0);
        minD = min(minD, abs(appleSum - (2 * sum)));
        return;
    }
    for (int i = id; i < apples.size(); i++)
    {
        temp.pub(apples[i]);
        helper(apples, temp, i + 1, appleSum, minD);
        temp.pob();
    }
}

void solve()
{
    ll minD;
    minD = LLONG_MAX;
    ll n;
    cin >> n;
    v64 apples(n);
    forn(i, n)
    {
        cin >> apples[i];
    }
    ll appleSum = accumulate(all(apples), 0);
    v64 temp;
    helper(apples, temp, 0, appleSum, minD);
    cout << minD << "\n";
    return;
}
int main()
{
    fast_cin();
    solve();
    return 0;
}