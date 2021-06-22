#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    string s;
    cin >> s;
    unordered_set<char> st(s.begin(), s.end());
    if (st.size() % 2)
    {
        cout << "IGNORE HIM!\n";
    }
    else
    {
        cout << "CHAT WITH HER!\n";
    }
    return 0;
}