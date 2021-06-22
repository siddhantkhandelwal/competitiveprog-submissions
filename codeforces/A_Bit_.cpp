#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    x = 0;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if (s[1] == '+')
        {
            x++;
        }
        else
        {
            x--;
        }
    }
    cout << x << "\n";
    return 0;
}