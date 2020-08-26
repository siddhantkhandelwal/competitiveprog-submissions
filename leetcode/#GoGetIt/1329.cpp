class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < (i ? 1 : n); j++)
            {
                vector<int> vals;
                while (i < m && j < n)
                {
                    vals.push_back(mat[i++][j++]);
                }
                sort(vals.begin(), vals.end());
                while (i && j)
                {
                    mat[--i][--j] = vals.back();
                    vals.pop_back();
                }
            }
        }
        return mat;
    }
};