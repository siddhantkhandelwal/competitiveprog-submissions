class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int n = nums.size();
        int max1 = 0;
        int start = 0, end = 0;
        while (end < n)
        {
            while (end < n && nums[end] == 0)
            {
                end++;
            }
            if (end == n)
            {
                return max1;
            }
            start = end;
            while (end < n && nums[end] == 1)
            {
                end++;
            }
            max1 = max(max1, end - start);
        }
        return max1;
    }
};