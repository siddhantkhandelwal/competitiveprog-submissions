class Solution
{
private:
    bool isPal(string &s, int start, int end)
    {
        if (start > end)
        {
            return false;
        }
        if (start == end)
        {
            return true;
        }
        while (start < end)
        {
            if (s[start++] != s[end--])
            {
                return false;
            }
        }
        return true;
    }

public:
    int countSubstrings(string s)
    {
        if (s.length() <= 1)
        {
            return s.length();
        }
        int n = s.length();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (isPal(s, j, i))
                {
                    dp[i]++;
                }
            }
            dp[i] += i > 0 ? dp[i - 1] : 0;
        }
        return dp[n - 1];
    }
};