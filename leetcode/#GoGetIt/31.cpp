class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int k = n - 2;
        while (k >= 0)
        {
            if (nums[k] < nums[k + 1])
            {
                break;
            }
            k--;
        }
        if (k < 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        int l = n - 1;
        while (l > k)
        {
            if (nums[l] > nums[k])
            {
                swap(nums[k], nums[l]);
                break;
            }
            l--;
        }
        reverse(nums.begin() + k + 1, nums.end());
    }
};