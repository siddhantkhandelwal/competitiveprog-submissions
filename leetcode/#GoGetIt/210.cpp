class Solution
{
public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> G(n);
        vector<int> degree(n, 0);
        vector<int> bfs;
        for (auto &p : prerequisites)
        {
            G[p[1]].push_back(p[0]);
            degree[p[0]]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (!degree[i])
            {
                bfs.push_back(i);
            }
        }
        for (int i = 0; i < bfs.size(); i++)
        {
            for (int j : G[bfs[i]])
            {
                if (--degree[j] == 0)
                {
                    bfs.push_back(j);
                }
            }
        }
        if (bfs.size() != n)
        {
            return {};
        }
        return bfs;
    }
};