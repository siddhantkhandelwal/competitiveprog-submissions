class Solution
{
private:
    void helper(vector<vector<int>> &cmbs, vector<int> &cmb, vector<int> &candidates, int target, int index, int k)
    {
        if (target == 0 && cmb.size() == k)
        {
            cmbs.push_back(cmb);
            return;
        }
        else if (cmb.size() > k)
        {
            return;
        }
        for (int i = index; i < candidates.size() && target >= candidates[i]; i++)
        {
            if (i == index || candidates[i] != candidates[i - 1])
            {
                cmb.push_back(candidates[i]);
                helper(cmbs, cmb, candidates, target - candidates[i], i + 1, k);
                cmb.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> cmbs;
        vector<int> cmb;
        vector<int> candidates;
        for (int i = 1; i <= 9; i++)
        {
            candidates.push_back(i);
        }
        helper(cmbs, cmb, candidates, n, 0, k);
        return cmbs;
    }
};