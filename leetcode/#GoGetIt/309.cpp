class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int sold = 0;
        int hold = INT_MIN;
        int rest = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            hold = max(hold, rest - prices[i]);
            rest = max(rest, sold);
            sold = hold + prices[i];
        }
        return max(rest, sold);
    }
};