class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n, INT_MAX);
        for (int i = 0; i < n; i++)
        {
            if (i < 2)
            {
                dp[i] = cost[i];
            }
            else
            {
                dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
            }
        }
        return min(dp[n - 1], dp[n - 2]);
    }
};

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        int first = cost[0];
        int second = cost[1];
        if (n <= 2)
        {
            return min(first, second);
        }
        for (int i = 2; i < n; i++)
        {
            int curr = cost[i] + min(first, second);
            first = second;
            second = curr;
        }
        return min(first, second);
    }
};