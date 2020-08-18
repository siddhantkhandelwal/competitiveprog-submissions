#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int sq[33];
    for (int i = 1; i <= 32; i++)
    {
        sq[i] = i * i;
    }
    while (t--)
    {
        int n;
        cin >> n;
        int c = 0;
        while (n > 0)
        {
            for (int i = 1; i <= 32; i++)
            {
                if (sq[i] <= n && sq[i + 1] > n)
                {
                    c++;
                    n = n - sq[i];
                }
            }
        }
        cout << c << endl;
    }
    return 0;
}
