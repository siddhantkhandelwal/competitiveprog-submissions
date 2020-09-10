#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int helper(ll nums[], ll t1)
{
    if (t1 == 0 || t1 == 1)
        return t1;

    ll t2[t1];
    ll j = 0;
    for (ll i = 0; i < t1 - 1; ++i)
    {
        if (nums[i] != nums[i + 1])
        {
            t2[j++] = nums[i];
        }
    }
    t2[j++] = nums[t1 - 1];

    for (ll i = 0; i < j; ++i)
    {
        nums[i] = t2[i];
    }
    return j;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll nums[n];
        for (ll i = 0; i < n; ++i)
        {
            cin >> nums[i];
        }
        sort(nums, nums + n);
        ll t1 = sizeof(nums) / sizeof(nums[0]);
        t1 = helper(nums, t1);
        if (nums[0] == 0)
        {
            t1--;
            cout << t1 << '\n';
        }
        else
        {
            cout << t1 << '\n';
        }
    }
    return 0;
}