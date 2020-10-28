class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        vector<bool> out;
        int max = *max_element(candies.begin(), candies.end());

        for (int i = 0; i < candies.size(); i++)
            candies[i] + extraCandies >= max ? out.push_back(true) : out.push_back(false);
        return out;
    }
};