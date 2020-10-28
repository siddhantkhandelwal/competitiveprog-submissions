class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return 0;
        }
        map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]].push_back(i);
        }
        int ans = 0;
        for (auto m : mp)
        {
            int t = m.second.size();
            if (t <= 1)
            {
                continue;
            }
            ans += t * (t - 1) / 2;
        }
        return ans;
    }
};