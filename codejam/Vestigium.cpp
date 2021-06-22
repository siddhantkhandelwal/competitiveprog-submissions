#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int t;
    cin >> t;
    int i = 1;
    while (t--)
    {
        ll r, c;
        ll n;
        cin >> n;
        ll trace = 0;
        vector<vector<ll>> mat(n, vector<ll>(n, 0));
        vector<vector<ll>> mat2(n, vector<ll>(n, 0));
        for (ll j = 0; j < n; j++)
        {
            for (ll k = 0; k < n; k++)
            {
                cin >> mat[j][k];
                mat2[k][j] = mat[j][k];
                if (j == k)
                {
                    trace += mat[j][k];
                }
            }
        }
        unordered_set<ll> rows, cols;
        for (int j = 0; j < n; j++)
        {
            unordered_set<ll> temp(mat[j].begin(), mat[j].end());
            if (temp.size() < n)
            {
                rows.insert(j);
            }
        }
        for (int j = 0; j < n; j++)
        {
            unordered_set<ll> temp(mat2[j].begin(), mat2[j].end());
            if (temp.size() < n)
            {
                cols.insert(j);
            }
        }
        cout << "Case #" << i++ << ": " << trace << " " << rows.size() << " " << cols.size() << "\n";
    }
    return 0;
}