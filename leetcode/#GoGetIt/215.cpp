class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> topK;
        for (auto num : nums)
        {
            topK.push(num);
            if (topK.size() > k)
            {
                topK.pop();
            }
        }
        return topK.top();
    }
};