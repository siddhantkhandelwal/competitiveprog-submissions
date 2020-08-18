class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < n; i++)
        {
            int target = -nums[i];
            int front = i + 1;
            int back = n - 1;
            if (target < 0)
            {
                break;
            }
            while (front < back)
            {
                int sum = nums[front] + nums[back];
                if (sum < target)
                {
                    front++;
                }
                else if (sum > target)
                {
                    back--;
                }
                else
                {
                    int t0 = nums[i];
                    int t1 = nums[front];
                    int t2 = nums[back];
                    res.push_back({t0, t1, t2});

                    while (front < back && nums[front] == t1)
                    {
                        front++;
                    }
                    while (front < back && nums[back] == t2)
                    {
                        back--;
                    }
                }
            }
            while (i < n - 1 && nums[i + 1] == nums[i])
            {
                i++;
            }
        }
        return res;
    }
};