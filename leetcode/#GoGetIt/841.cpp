class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        stack<int> dfs;
        dfs.push(start);
        unordered_set<int> visited = {0};
        while (!dfs.empty())
        {
            int i = dfs.top();
            dfs.pop();
            if (arr[i] == 0)
            {
                return true;
            }
            if (arr[i] + i < n)
            {
                if (visited.count(arr[i] + i) == 0)
                {
                    dfs.push(arr[i] + i);
                    visited.insert(i + arr[i]);
                }
            }
            if (i - arr[i] >= 0)
            {
                if (visited.count(i - arr[i]) == 0)
                {
                    dfs.push(i - arr[i]);
                    visited.insert(i - arr[i]);
                }
            }
        }
        return false;
    }
};