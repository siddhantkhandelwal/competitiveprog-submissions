class Solution
{
public:
    void dfsB(vector<vector<char>> &board, int i, int j, int m, int n)
    {
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O')
            return;
        board[i][j] = '#';
        dfsB(board, i - 1, j, m, n);
        dfsB(board, i + 1, j, m, n);
        dfsB(board, i, j - 1, m, n);
        dfsB(board, i, j + 1, m, n);
    }
    void solve(vector<vector<char>> &board)
    {
        int m = board.size();
        if (!m)
        {
            return;
        }
        int n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O')
            {
                dfsB(board, i, 0, m, n);
            }
            if (board[i][n - 1] == 'O')
            {
                dfsB(board, i, n - 1, m, n);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (board[0][i] == 'O')
            {
                dfsB(board, 0, i, m, n);
            }
            if (board[m - 1][i] == 'O')
            {
                dfsB(board, m - 1, i, m, n);
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '#')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
};