class Solution
{
public:
    int sumSubarrayMins(vector<int> &A)
    {
        int n = A.size();
        stack<pair<int, int>> ple, nle;
        vector<int> left(n), right(n);
        for (int i = 0; i < n; i++)
        {
            left[i] = i + 1;
        }
        for (int i = 0; i < n; i++)
        {
            right[i] = n - i;
        }
        for (int i = 0; i < n; i++)
        {
            while (!ple.empty() && ple.top() > A[i])
            {
                ple.pop();
            }
            left[i] = ple.empty() ? i + 1 : i - ple.top().second;
            ple.push({A[i], i});

            while (!nle.empty() && nle.top() > A[i])
            {
                auto x = nle.top();
                nle.pop();
                right[x.second] = i - x.second;
            }
            nle.push({A[i], i});
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = (ans + (left[i] * A[i] * right[i] % 1000000007)) % 1000000007;
        }
        return ans;
    }
};