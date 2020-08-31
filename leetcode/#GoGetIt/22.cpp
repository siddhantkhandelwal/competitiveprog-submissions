class Solution
{
private:
    void helper(int n, string t, vector<string> &ans, int m)
    {
        if (n == 0 && m == 0)
        {
            ans.push_back(t);
            return;
        }
        if (m > 0)
        {
            helper(n, t + ')', ans, m - 1);
        }
        if (n > 0)
        {
            helper(n - 1, t + '(', ans, m + 1);
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string t;
        helper(n, t, ans, 0);
        return ans;
    }
};