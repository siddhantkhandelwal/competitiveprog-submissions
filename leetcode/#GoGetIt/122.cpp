class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int i = 0;
        int n = prices.size() - 1;
        int profit = 0;
        while (i < n)
        {
            int buy;
            int sell;
            while (i < n && prices[i + 1] <= prices[i])
            {
                i++;
            }
            buy = prices[i];
            while (i < n && prices[i + 1] > prices[i])
            {
                i++;
            }
            sell = prices[i];
            profit += sell - buy;
        }
        return profit;
    }
};