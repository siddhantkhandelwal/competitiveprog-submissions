class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        map<char, int> mp;
        int n = s.length();
        int start = -1;
        int maxLen = 0;

        for (int i = 0; i < n; i++)
        {
            if (mp.count(s[i]) != 0)
            {
                start = max(start, mp[s[i]]);
            }
            mp[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }

        return maxLen;
    }
};