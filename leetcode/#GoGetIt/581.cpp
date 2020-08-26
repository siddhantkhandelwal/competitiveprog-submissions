class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return 0;

        int left = 0, right = n - 1;
        while (left < n - 1 && nums[left] <= nums[left + 1])
            ++left;
        if (left == n - 1)
            return 0;
        while (right > 0 && nums[right] >= nums[right - 1])
            --right;

        int rmin = INT_MAX, lmax = INT_MIN;
        for (int i = left; i <= right; ++i)
        {
            if (nums[i] > lmax)
                lmax = nums[i];
            if (nums[i] < rmin)
                rmin = nums[i];
        }
        while (left >= 0 && nums[left] > rmin)
            --left;
        while (right < n && nums[right] < lmax)
            ++right;
        return right - left - 1;
    }
};