class Solution
{
private:
    int helper(int l, int r, string &s, vector<vector<int>> &dp)
    {
        if (l == r)
        {
            return 1;
        }
        if (l > r)
        {
            return 0;
        }
        if (dp[l][r])
        {
            return dp[l][r];
        }
        return dp[l][r] = (s[l] == s[r] ? 2 + helper(l + 1, r - 1, s, dp) : max(helper(l + 1, r, s, dp), helper(l, r - 1, s, dp)));
    }

public:
    int longestPalindromeSubseq(string s)
    {
        vector<vector<int>> dp(n, vector<int>(n));
        int n = s.length();
        return helper(0, n - 1, s, dp);
    }
};