class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (matrix.size() < 1)
        {
            return {};
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int cb = 0;
        int rb = 0;
        int re = m - 1;
        int ce = n - 1;
        vector<int> ans;
        while (rb <= re && cb <= ce)
        {
            for (int i = cb; i <= ce; i++)
            {
                ans.push_back(matrix[rb][i]);
            }
            rb++;
            for (int i = rb; i <= re; i++)
            {
                ans.push_back(matrix[i][ce]);
            }
            ce--;
            if (rb <= re)
            {
                for (int i = ce; i >= cb; i--)
                {
                    ans.push_back(matrix[re][i]);
                }
            }
            re--;
            if (cb <= ce)
            {
                for (int i = re; i >= rb; i--)
                {
                    ans.push_back(matrix[i][cb]);
                }
            }
            cb++;
        }
        return ans;
    }
};