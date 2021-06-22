#include <iostream>
using namespace std;

int graph[100][100];
int n;

bool dfs(int node, bool *visited, bool *inloop, int &prev)
{
    visited[node] = true;
    inloop[node] = true;
    for (int i = 0; i < n; i++)
    {
        if (graph[node][i])
        {
            if (!visited[i])
            {
                if (dfs(i, visited, inloop, prev))
                {
                    if (i == prev)
                    {
                        cout << i << " ", prev = -1;
                    }
                    else if (prev != -1)
                    {
                        cout << i << " ";
                    }
                    return true;
                }
                else if (inloop[i])
                {
                    prev = i;
                    return true;
                }
            }
        }
    }
    inloop[node] = false;
    return false;
}

bool checkCycle(bool *visited)
{
    int prev = -1;
    bool inloop[n] = {false};
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && dfs(i, visited, inloop, prev))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }
    int t;
    cin >> t;
    int x, y;
    for (int i = 0; i < t; i++)
    {
        cin >> x >> y;
        graph[x][y] = 1;
    }
    bool visited[n] = {false};
    cout << checkCycle(visited) << endl;
    return 0;
}