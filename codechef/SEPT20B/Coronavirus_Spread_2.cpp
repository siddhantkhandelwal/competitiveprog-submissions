#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        int a = n / 4;
        int b = 2 * a;
        int c = 3 * a;
        if (arr[a] == arr[a - 1] || arr[b] == arr[b - 1] || arr[c] == arr[c - 1])
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << arr[a] << " " << arr[b] << " " << arr[c] << "\n";
        }
    }
    return 0;
}