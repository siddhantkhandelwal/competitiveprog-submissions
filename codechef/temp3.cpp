#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        string s1, s2, s;
        cin >> s1 >> s2;
        ll n = s1.size(), m = s2.size();
        ll count[27];
        memset(count, 0, sizeof(count));
        ll count1[27];
        for (int i = 0; i < n; i++)
        {
            count[s1[i] - 'a']++;
        }
        for (int i = 0; i < m; i++)
        {
            count[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
            count1[i] = count[i];
        for (int i = 0; i <= (s2[0] - 'a'); i++)
        {
            while (count[i] > 0)
            {
                s += (char)(i + 97);
                count[i]--;
            }
        }
        s += s2;
        for (int i = 0; i < 26; i++)
        {
            while (count[i] > 0)
            {
                s += (char)(i + 97);
                count[i]--;
            }
        }
        string sfinal;
        for (int i = 0; i < s2[0] - 'a'; i++)
        {
            while (count1[i] != 0)
            {
                sfinal += (char)(i + 97);
                count1[i]--;
            }
        }
        sfinal += s2;
        for (int i = 0; i < 26; i++)
        {
            while (count1[i] != 0)
            {
                sfinal += (char)(i + 97);
                count1[i]--;
            }
        }
        cout << min(s, sfinal) << "\n";
    }
}
