#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int j, sum = 0;
        for (j = 1; j <= n; j++)
        {
            if (j % 2 != 0)
            {
                sum = sum + ((n - j + 1) * (n - j + 1));
            }
        }
        cout << sum << endl;
    }
    return 0;
}