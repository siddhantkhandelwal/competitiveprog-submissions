#include <bits/stdc++.h>
#define ll long long int

using namespace std;

// ll power(ll x, ll y, ll p)
// {
//     ll res = 1;
//     x = x % p;
//     if (!x)
//     {
//         return 0;
//     }
//     while (y > 0)
//     {
//         if (y & 1)
//         {
//             res = (res * x) % p;
//         }
//         y = y >> 1;
//         x = (x * x) % p;
//     }
//     return res;
// }

void printSubsequences(vector<vector<ll>> &subseq, vector<ll> &arr, ll index,
                       vector<ll> subarr)
{
    if (index == arr.size())
    {
        int l = subarr.size();

        // Condition to avoid printing
        // empty subsequence
        if (l != 0)
            subseq.push_back(subarr);
    }
    else
    {
        // Subsequence without including
        // the element at current index
        printSubsequences(subseq, arr, index + 1, subarr);

        subarr.push_back(arr[index]);

        // Subsequence including the element
        // at current index
        printSubsequences(subseq, arr, index + 1, subarr);
    }
    return;
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
        vector<ll> val;
        for (ll i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            val.push_back(temp);
        }
        sort(val.begin(), val.end());
        vector<vector<ll>> subseq;
        vector<ll> subarr;
        printSubsequences(subseq, val, 0, subarr);
        // cout<<"\n\n";
        // for (auto sub : subseq)
        // {
        //     for (auto n : sub)
        //     {
        //         cout << n << " ";
        //     }
        //     cout << "\n";
        // }
        ll valcount[n + 1] = {0};
        for (auto seq : subseq)
        {
            ll c[n + 1] = {0};
            for (auto n : seq)
            {
                c[n]++;
            }
            ll maxcount = INT_MIN;
            ll maxN;
            for (int i = 1; i <= n; i++)
            {
                if (c[i] > maxcount)
                {
                    maxN = i;
                    maxcount = c[i];
                }
            }
            valcount[maxN]++;
        }
        for (int i = 1; i <= n; i++)
        {
            cout << valcount[i] << " ";
        }
        cout << endl;
    }
    return 0;
}