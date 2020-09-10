class Solution
{
public:
    int largestRectangleArea(vector<int> &h)
    {
        h.push_back(0);
        int n = h.size();
        stack<int> st;
        int ans = 0;
        int i = 0;
        while (i < n)
        {
            if (!st.empty() && h[i] < h[st.top()])
            {
                int t = st.top();
                st.pop();
                int ar = h[t] * (st.empty() ? i : (i - st.top() - 1));
                ans = max(ans, ar);
            }
            else
            {
                st.push(i);
                i++;
            }
        }
        return ans;
    }
};