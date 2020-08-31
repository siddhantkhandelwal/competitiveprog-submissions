class Solution
{
public:
    vector<int> sortedSquares(vector<int> &A)
    {
        vector<int> ans;
        int n = A.size();
        int start = 0;
        int end = n - 1;
        while (start <= end)
        {
            if (A[start] * A[start] <= A[end] * A[end])
            {
                ans.push_back(A[end] * A[end]);
                end--;
            }
            else
            {
                ans.push_back(A[start] * A[start]);
                start++;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};