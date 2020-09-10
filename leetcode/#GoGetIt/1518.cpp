class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        long long int eb = 0;
        long long int nb = numBottles;
        long long int tot = 0;
        while (nb != 0)
        {
            tot += nb;
            eb += nb;
            nb = eb / numExchange;
            eb = eb % numExchange;
        }
        return tot;
    }
};