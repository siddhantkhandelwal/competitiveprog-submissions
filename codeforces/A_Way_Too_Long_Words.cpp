#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        if (s.length() > 10)
        {

            char start = s[0];
            char end = s[s.length() - 1];
            s = start + to_string(s.length() - 2) + end;
        }

        cout << s << endl;
    }
    return 0;
}