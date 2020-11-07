class Solution
{
public:
    string minWindow(string s, string t)
    {
        size_t start = 0, end = 0, counter = t.size(), minStart = 0, minLen = INT_MAX;
        vector<int> m(128, 0);
        for (auto c : t)
        {
            m[c]++;
        }
        while (end < s.size())
        {
            if (m[s[end]] > 0)
            {
                counter--;
            }
            m[s[end]]--;
            end++;
            while (counter == 0)
            {
                if (end - start < minLen)
                {
                    minStart = start;
                    minLen = end - start;
                }
                m[s[start]]++;
                if (m[s[start]] > 0)
                {
                    counter++;
                }
                start++;
            }
        }
        if (minLen == INT_MAX)
        {
            return "";
        }
        return s.substr(minStart, minLen);
    }
};