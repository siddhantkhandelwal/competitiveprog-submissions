#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    if (s.size())
    {
        s[0] = toupper(s[0]);
    }
    cout << s << "\n";
    return 0;
}