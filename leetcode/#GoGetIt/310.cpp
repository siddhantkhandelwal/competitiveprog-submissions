class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        vector<int> result;
        if (n == 1)
        {
            result.push_back(0);
            return result;
        }
        vector<unordered_set<int>> graph(n, unordered_set<int>());
        for (int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].insert(edges[i][1]);
            graph[edges[i][1]].insert(edges[i][0]);
        }
        vector<int> degree(n, 0);
        for (int i = 0; i < n; i++)
        {
            degree[i] = graph[i].size();
        }
        int count = n;
        while (count > 2)
        {
            vector<int> record;
            for (int i = 0; i < n; i++)
            {
                if (degree[i] == 1)
                {
                    count--;
                    degree[i] = -1;
                    record.push_back(i);
                }
            }
            for (int i = 0; i < record.size(); i++)
            {
                for (auto it : graph[record[i]])
                    degree[it]--;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (degree[i] == 1 || degree[i] == 0)
                result.push_back(i);
        }
        return result;
    }
};