class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int first = 0;
        int second = height.size() - 1;
        int maxWa = INT_MIN;
        while (first < second)
        {
            maxWa = max(maxWa, (second - first) * min(height[first], height[second]));
            if (height[first] >= height[second])
            {
                second--;
            }
            else
            {
                first++;
            }
        }
        return maxWa;
    }
};