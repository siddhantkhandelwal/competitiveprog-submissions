class Solution
{
private:
    void helper(vector<int> &nums, vector<int> subset, set<vector<int>> &subsets, int index)
    {
        sort(subset.begin(), subset.end());
        subsets.insert(subset);
        if (index == nums.size())
        {
            return;
        }
        helper(nums, subset, subsets, index + 1);
        subset.push_back(nums[index]);
        helper(nums, subset, subsets, index + 1);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        if (nums.size() < 1)
        {
            return {};
        }
        sort(nums.begin(), nums.end());
        vector<int> subset;
        set<vector<int>> subsets;
        helper(nums, subset, subsets, 0);
        vector<vector<int>> ans;
        for (auto s : subsets)
        {
            ans.push_back(s);
        }
        return ans;
    }
};