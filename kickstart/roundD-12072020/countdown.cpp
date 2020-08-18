#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    int j = 1;
    while (j <= t)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> nums;
        for (int i = 0; i < n; i++)
        {
            ll temp;
            cin >> temp;
            nums.push_back(temp);
        }
        ll answer_counter = 0;
        ll decreasing_counter = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1] - 1)
            {
                decreasing_counter++;
            }
            else
            {
                decreasing_counter = 0;
            }
            if (nums[i] == 1 && decreasing_counter >= k - 1)
            {
                answer_counter++;
            }
        }
        cout << "Case #" << j << ": " << answer_counter << "\n";
        j++;
    }
    return 0;
}