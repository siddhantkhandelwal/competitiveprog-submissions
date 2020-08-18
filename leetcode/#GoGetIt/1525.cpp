class Solution
{
public:
    int numSplits(string s)
    {
        int n = s.length();
        vector<int> pref(n), suff(n);
        unordered_map<char, int> freq;
        for (int i = 0; i < n; i++)
        {
            freq[s[i]]++;
            pref[i] = freq.size();
        }
        freq.clear();
        for (int i = n - 1; i >= 0; i--)
        {
            freq[s[i]]++;
            suff[i] = freq.size();
        }
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            if (pref[i - 1] == suff[i])
                ans++;
        }
        return ans;
    }
};