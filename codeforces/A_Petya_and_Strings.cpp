#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    int ans;
    if (s1 == s2)
    {
        ans = 0;
    }
    else if (s1 < s2)
    {
        ans = -1;
    }
    else
    {
        ans = 1;
    }
    cout << ans << "\n";
    return 0;
}