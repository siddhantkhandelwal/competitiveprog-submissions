class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i < amount + 1; i++)
        {
            for (int j = coins.size() - 1; j >= 0; j--)
            {
                if (coins[j] <= i)
                {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};