class Solution
{
public:
    int numberOfSubarrays(vector<int> &A, int K)
    {
        return helper(A, K) - helper(A, K - 1);
    }
    int helper(vector<int> &A, int K)
    {
        int oddCount = 0, l = 0;
        int count = 0;
        for (int r = 0; r < A.size(); ++r)
        {
            if (A[r] % 2)
                ++oddCount;
            while (l <= r && oddCount > K)
            {
                if (A[l] % 2)
                    --oddCount;
                ++l;
            }
            count += (r - l + 1);
        }
        return count;
    }
};