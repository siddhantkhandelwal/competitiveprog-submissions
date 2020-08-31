class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int> stk;
        int n = s.length();
        int ans = 0;
        stk.push(-1);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                stk.push(i);
            }
            else
            {
                stk.pop();
                if (stk.empty())
                {
                    stk.push(i);
                }
                else
                {
                    ans = max(ans, i - stk.top());
                }
            }
        }
        return ans;
    }
};