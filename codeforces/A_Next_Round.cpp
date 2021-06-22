#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int bs_right(vector<ll> &nums, ll l, ll r, ll target)
{
    ll ans = -1;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        if (nums[mid] == target)
        {
            ans = mid;
            l = mid + 1;
        }
        else if (nums[mid] < target)
        {
            r = mid - 1;
        }
        else if (nums[mid] > target)
        {
            l = mid + 1;
        }
    }
    return ans;
}

int bs_left(vector<ll> &nums, ll l, ll r, ll target)
{
    ll ans = -1;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        if (nums[mid] == target)
        {
            ans = mid;
            r = mid - 1;
        }
        else if (nums[mid] < target)
        {
            r = mid - 1;
        }
        else if (nums[mid] > target)
        {
            l = mid + 1;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    ll ans;
    cin >> n >> k;
    vector<ll> nums(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    if (nums[k - 1] == 0)
    {
        int id = bs_left(nums, 0, k - 1, nums[k - 1]);
        cout << id << "\n";
    }
    else
    {
        int id = bs_right(nums, k - 1, n - 1, nums[k - 1]);
        cout << id + 1 << "\n";
    }
    return 0;
}