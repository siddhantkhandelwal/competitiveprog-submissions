#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        string t;
        cin >> s >> t;
        int n = s.size();
        int m = t.size();
        if (!n && !m)
        {
            cout << 0;
            return 0;
        }
        if (!n || !m)
        {
            cout << !n ? m : n;
        }
        int res = 0;
        int sStart = 0;
        int tStart = 0;
        vector<vector<int>> dp(2, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
                    if (dp[i % 2][j] > res)
                    {
                        res = dp[i % 2][j];
                        sStart = i - 1;
                        tStart = j - 1;
                    }
                }
                else
                    dp[i % 2][j] = 0;
            }
        }
        cout << sStart + n - (sStart + res) + tStart + m - (tStart + res) << "\n";
    }
    return 0;
}