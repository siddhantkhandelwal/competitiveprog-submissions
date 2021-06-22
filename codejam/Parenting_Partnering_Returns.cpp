#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

int main()
{
    int t;
    cin >> t;
    int i = 1;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<pair<int, int>> acts;
        for (ll j = 0; j < n; j++)
        {
            ll s, e;
            cin >> s >> e;
            acts.push_back({s, e});
        }
        sort(acts.begin(), acts.end(), cmp);
        string ans;
        vector<pair<int, int>> j, c;
        for (int k = 0; k < n; k++)
        {
            if (!c.size() || c.back().second <= acts[k].first)
            {
                c.push_back(acts[k]);
                ans += 'C';
            }
            else if (!j.size() || j.back().second <= acts[k].first)
            {
                j.push_back(acts[k]);
                ans += 'J';
            }
            else
            {
                ans = "IMPOSSIBLE";
                break;
            }
        }
        cout << "Case #" << i++ << ": " << ans << "\n";
    }
    return 0;
}