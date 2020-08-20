class Solution
{
public:
    int dfs(vector<int> &A, int K, int start, vector<int> &dp)
    {
        int n = A.size();
        if (start >= n)
        {
            return 0;
        }
        if (dp[start] != 0)
        {
            return dp[start];
        }
        int maxSum = 0;
        int maxEle = 0;
        for (int i = start; i < min(n, start + K); i++)
        {
            maxEle = max(maxEle, A[i]);
            maxSum = max(maxSum, maxEle * (i - start + 1) + dfs(A, K, i + 1, dp));
        }
        dp[start] = maxSum;
        return maxSum;
    }
    int maxSumAfterPartitioning(vector<int> &A, int K)
    {
        int n = A.size();
        vector<int> dp(n, 0);
        return dfs(A, K, 0, dp);
    }
};