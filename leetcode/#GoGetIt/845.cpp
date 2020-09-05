class Solution
{
public:
    int longestMountain(vector<int> &A)
    {
        int n = A.size();
        int maxLen = 0;
        int i = 1;
        while (i < n)
        {
            while (i < n && A[i] == A[i - 1])
            {
                i++;
            }
            int up = 0;
            while (i < n && A[i] > A[i - 1])
            {
                up++;
                i++;
            }
            int down = 0;
            while (i < n && A[i] < A[i - 1])
            {
                down++;
                i++;
            }
            if (up > 0 && down > 0)
            {
                maxLen = max(maxLen, up + down + 1);
            }
        }
        return maxLen;
    }
};