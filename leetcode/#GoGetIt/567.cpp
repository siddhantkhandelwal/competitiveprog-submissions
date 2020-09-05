class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        vector<int> subs(26), cnt(26);
        for (auto c : s1)
        {
            cnt[c - 'a']++;
        }
        for (int i = 0; i < s2.length(); i++)
        {
            subs[s2[i] - 'a']++;
            if (i >= s1.length())
            {
                subs[s2[i - s1.size()] - 'a']--;
            }
            if (cnt == subs)
            {
                return true;
            }
        }
        return false;
    }
};