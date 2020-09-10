class Solution
{
public:
    struct comp
    {
        bool operator()(const pair<int, string> &lhs, const pair<int, string> &rhs) const
        {
            if (lhs.first != rhs.first)
            {
                return lhs.first < rhs.first;
            }
            return lhs.second > rhs.second;
        }
    };
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        int n = words.size();
        if (!n)
        {
            return {};
        }
        unordered_map<string, int> mp;
        for (auto w : words)
        {
            mp[w]++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, comp> pq;
        for (auto m : mp)
        {
            pq.push({m.second, m.first});
        }
        vector<string> res;
        while (k-- && pq.size())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};