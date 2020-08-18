#include <bits/stdc++.h>
using namespace std;
int main()
{
    int w;
    cin >> w;
    string yes = "YES";
    string no = "NO";
    if (!(w & 1) && w != 2)
    {
        cout << yes << endl;
    }
    else
    {
        cout << no << endl;
    }
    return 0;
}