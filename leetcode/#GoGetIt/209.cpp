class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int l = 0;
        int r = 0;
        int n = nums.size();
        int sum = 0;
        int minLen = INT_MAX;
        while (r < n)
        {
            sum += nums[r];
            while (sum >= s)
            {
                minLen = min(minLen, r - l + 1);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};