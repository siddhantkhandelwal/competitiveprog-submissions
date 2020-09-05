class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int l = 0;
        int r = 0;
        int n = nums.size();
        int prod = 1;
        int cnt = 0;
        while (r < n)
        {
            prod = prod * nums[r];
            while (l <= r && prod >= k)
            {
                prod = prod / nums[l];
                l++;
            }
            cnt += r - l + 1;
            r++;
        }
        return cnt;
    }
};