class Solution
{
private:
    void helper(vector<vector<int>> &cmbs, vector<int> &cmb, vector<int> &candidates, int target, int index)
    {
        if (target == 0)
        {
            cmbs.push_back(cmb);
            return;
        }
        for (int i = index; i < candidates.size() && target >= candidates[i]; i++)
        {
            cmb.push_back(candidates[i]);
            helper(cmbs, cmb, candidates, target - candidates[i], i);
            cmb.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> cmbs;
        vector<int> cmb;
        sort(candidates.begin(), candidates.end());
        helper(cmbs, cmb, candidates, target, 0);
        return cmbs;
    }
};