class Solution
{
public:
    int findJudge(int N, vector<vector<int>> &trust)
    {
        vector<vector<int>> mp(N);
        unordered_map<int, int> m;
        for (auto t : trust)
        {
            mp[t[0] - 1].push_back(t[1] - 1);
            m[t[1] - 1]++;
        }
        set<int> plausible;
        for (int i = 0; i < N; i++)
        {
            if (mp[i].size() == 0)
            {
                plausible.insert(i);
            }
        }
        for (auto p : plausible)
        {
            if (m[p] == N - 1)
            {
                return p + 1;
            }
        }
        return -1;
    }
};