class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        int l = nums.size();
        if (n == 1)
        {
            return nums;
        }
        for (int i = 0; i < l; i++)
        {
            int j = i;
            int buffer = nums[i];
            while (buffer >= 0)
            {
                j = j < n ? j * 2 : (j - n) * 2 + 1;
                int temp = buffer;
                buffer = nums[j];
                nums[j] = -temp;
            }
        }
        for (int i = 0; i < l; i++)
        {
            nums[i] = -nums[i];
        }
        return nums;
    }
};