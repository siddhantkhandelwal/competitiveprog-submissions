#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int id = 0;
    while (id < 25)
    {
        int temp;
        cin >> temp;
        id++;
        if (temp == 1)
        {
            break;
        }
    }
    id--;
    cout << abs(2 - (id / 5)) + abs(2 - (id % 5)) << "\n";
    return 0;
}