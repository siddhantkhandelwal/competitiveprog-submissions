#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long int t;
    cin >> t;
    int j = 1;
    while (j <= t)
    {
        long int n;
        long int ans = 0;
        long int lastVal = INT_MIN;
        long int maxNow = INT_MIN;
        cin >> n;
        if (n <= 1)
        {
            cout << "Case #" << j << ": " << 0 << endl;
            continue;
        }
        while (n)
        {
            long int val;
            cin >> val;
            if (lastVal > maxNow)
            {
                maxNow = lastVal;
                if (lastVal > val)
                {
                    ans++;
                }
            }
            n--;
            lastVal = val;
        }
        if (lastVal > maxNow)
        {
            maxNow = lastVal;
            ans++;
        }
        cout << "Case #" << j << ": " << ans << endl;
        j++;
    }
    return 0;
}