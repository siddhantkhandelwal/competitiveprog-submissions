#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    char c = 'x';
    ll ans = 0;
    int n;
    cin >> n;
    while (n--)
    {
        char temp;
        cin >> temp;
        if (c != 'x' && temp == c)
        {
            ans++;
        }
        c = temp;
    }
    cout << ans << "\n";
    return 0;
}