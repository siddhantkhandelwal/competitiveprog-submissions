class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        int i = 0;
        int j = 0;
        string res = "";
        string temp = lcs(str1, str2);
        for (char c : temp)
        {
            while (str1[i] != c)
            {
                res += str1[i];
                i++;
            }
            while (str2[j] != c)
            {
                res += str2[j];
                j++;
            }
            res += c;
            i++;
            j++;
        }
        return res + str1.substr(i) + str2.substr(j);
    }
    string lcs(string &A, string &B)
    {
        int n = A.length();
        int m = B.length();
        vector<vector<string>> dp(n + 1, vector<string>(m + 1, ""));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (A[i - 1] == B[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + A[i - 1];
                }
                else
                {
                    dp[i][j] = dp[i][j - 1].size() > dp[i - 1][j].size() ? dp[i][j - 1] : dp[i - 1][j];
                }
            }
        }
        return dp[n][m];
    }
};