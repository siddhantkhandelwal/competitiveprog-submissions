class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {

        int totalorange = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] != 0)
                    totalorange++;
                if (grid[i][j] == 2)
                    q.push(make_pair(i, j));
            }
        }

        int time = -1;

        while (!q.empty())
        {
            time++;
            int s = q.size();

            for (int i = 0; i < s; i++)
            {
                pair<int, int> ind = q.front();
                q.pop();

                int x = ind.first;
                int y = ind.second;

                if (x - 1 >= 0 && grid[x - 1][y] == 1)
                {
                    q.push(make_pair(x - 1, y));
                    grid[x - 1][y] = 2;
                }
                if (x + 1 < grid.size() && grid[x + 1][y] == 1)
                {
                    q.push(make_pair(x + 1, y));
                    grid[x + 1][y] = 2;
                }
                if (y - 1 >= 0 && grid[x][y - 1] == 1)
                {
                    q.push(make_pair(x, y - 1));
                    grid[x][y - 1] = 2;
                }
                if (y + 1 < grid[0].size() && grid[x][y + 1] == 1)
                {
                    q.push(make_pair(x, y + 1));
                    grid[x][y + 1] = 2;
                }
            }
        }

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return max(time, 0);
    }
};