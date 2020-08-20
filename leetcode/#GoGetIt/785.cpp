class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        map<int, int> colour;
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (colour.find(i) != colour.end())
            {
                continue;
            }
            colour[i] = 1;
            q.push(i);
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();
                for (auto n : graph[cur])
                {
                    if (colour.find(n) == colour.end())
                    {
                        colour[n] = -colour[cur];
                        q.push(n);
                    }
                    else if (colour[n] == colour[cur])
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};