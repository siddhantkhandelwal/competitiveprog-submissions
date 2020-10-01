#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        int count = 0;
        for (int i = n - 1; i > 0; i--)
        {
            if (a[i][i] != a[i][i - 1] + 1)
            {
                count++;
                for (int x = 0; x < i + 1; x++)
                {
                    for (int y = x; y < i + 1; y++)
                    {
                        swap(a[x][y], a[y][x]);
                    }
                }
            }
            else
            {
                continue;
            }
        }
        cout << count << "\n";
    }
    return 0;
}