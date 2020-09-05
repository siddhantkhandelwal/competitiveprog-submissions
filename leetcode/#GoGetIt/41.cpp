class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int s = nums.size();
        sort(nums.begin(), nums.end());
        int f = s + 2;
        for (int i = 0; i < s; i++)
        {
            if (nums[i] <= 0 || nums[i] > s)
            {
                nums[i] = f;
            }
        }
        for (int i = 0; i < s; i++)
        {
            if (nums[i] == f || nums[i] == -f)
            {
                continue;
            }
            int v = abs(nums[i]);
            nums[v - 1] = -abs(nums[v - 1]);
        }
        for (int i = 0; i < s; i++)
        {
            if (nums[i] > 0)
            {
                return i + 1;
            }
        }
        return s + 1;
    }
};