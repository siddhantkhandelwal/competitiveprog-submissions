class Solution
{
private:
    void helper(string &s, vector<string> &parts, vector<vector<string>> &ans, int start)
    {
        if (start == s.length())
        {
            ans.push_back(parts);
            return;
        }
        for (int i = start; i < s.length(); i++)
        {
            if (isPal(s, start, i))
            {
                parts.push_back(s.substr(start, i - start + 1));
                helper(s, parts, ans, i + 1);
                parts.pop_back();
            }
        }
    }
    bool isPal(string &s, int start, int end)
    {
        if (start > end)
        {
            return false;
        }
        while (start <= end)
        {
            if (s[start++] != s[end--])
            {
                return false;
            }
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s)
    {
        int n = s.length();
        if (n <= 0)
        {
            return {};
        }
        vector<string> parts;
        vector<vector<string>> ans;
        helper(s, parts, ans, 0);
        return ans;
    }
};