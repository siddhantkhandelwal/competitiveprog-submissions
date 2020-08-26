class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        int n = rating.size();
        if (n < 3)
        {
            return 0;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int less[2] = {}, greater[2] = {};
            for (int j = 0; j < n; j++)
            {
                if (rating[i] < rating[j])
                {
                    less[i < j]++;
                }
                if (rating[i] > rating[j])
                {
                    greater[i < j]++;
                }
            }
            ans += less[0] * greater[1] + less[1] * greater[0];
        }
        return ans;
    }
};