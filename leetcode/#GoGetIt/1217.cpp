class Solution
{
public:
    int minCostToMoveChips(vector<int> &position)
    {
        int odd = 0, even = 0;
        for (auto ele : position)
        {
            if (ele % 2 != 0)
                odd++;
            else
                even++;
        }
        return min(odd, even);
    }
};