#include <bits/stdc++.h>

#define ll long long int

using namespace std;

bool check(vector<ll> &v)
{
    for (ll i = 0; i < v.size() - 1; i++)
    {
        if ((v[i] & v[i + 1]) <= 0)
        {
            return false;
        }
    }
    return true;
}

void helper(vector<ll> &v, vector<vector<ll>> &ans, ll start)
{
    if (start >= v.size() || ans.size())
    {
        return;
    }
    else if (check(v))
    {
        ans.push_back(v);
        return;
    }
    for (ll i = start; i < v.size(); i++)
    {
        swap(v[i], v[start]);
        helper(v, ans, start + 1);
        swap(v[i], v[start]);
    }
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> v;
        for (ll i = 1; i <= n; i++)
        {
            v.push_back(i);
        }
        vector<vector<ll>> ans;
        helper(v, ans, 0);
        if (!ans.size())
        {
            cout << -1 << endl;
        }
        else
        {
            auto t = ans[0];
            for (auto e : t)
            {
                cout << e << " ";
            }
            cout << endl;
        }
    }
    return 0;
}