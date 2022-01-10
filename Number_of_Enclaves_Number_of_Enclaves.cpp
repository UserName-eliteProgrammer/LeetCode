class Solution
{
public:
    int ans = 0;
    bool flag = true;
    void dfs(int i, int j, int m, int n, vector<vector<int>> &grid)
    {   
        if(grid[i][j] != 1)
        {
            return;
        }
        if((i == 0 or i == m - 1 or j == 0 or j == n - 1))
        {
            flag = false;
            // return;
        }

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        ans++;

        grid[i][j] = 2;
        for (int k = 0; k < 4; k++)
        {   
            int newX = i + dx[k];
            int newY = j + dy[k];
            if(newX >= 0 and newX < m and newY >= 0 and newY < n)
            {
                dfs(newX, newY, m, n, grid);
            }        
        }

        if(flag == false)
        {
            ans--;
        }    
    }

    int numEnclaves(vector<vector<int>>& grid) 
    {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {   
                if(grid[i][j] == 1)
                {   
                    dfs(i, j, grid.size(), grid[0].size(), grid);
                    flag = true;
                }
            }
        }
        return ans;
    }
};