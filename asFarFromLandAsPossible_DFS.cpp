class Solution 
{
public:
    int dfs(int i, int j, int n, int dis, vector<vector<int>> &grid, vector<vector<bool>> &vis)
    {   
        if(i >= n or j >= n or i < 0 or j < 0 or vis[i][j] == true)
        {
            return INT32_MAX;
        }
        if(grid[i][j] == 1)
        {
            return dis;
        }

        vis[i][j] = true;
        int temp1 = dfs(i + 1, j, n, dis + 1, grid, vis);
        int temp2 = dfs(i - 1, j, n, dis + 1, grid, vis);
        int temp3 = dfs(i, j + 1, n, dis + 1, grid, vis);
        int temp4 = dfs(i, j - 1, n, dis + 1, grid, vis);
        vis[i][j] = false;
        return min(temp1, min(temp2, min(temp3, temp4)));
    }

    int maxDistance(vector<vector<int>>& grid) 
    {   
        int ans = INT32_MIN, n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++)
        {   
            for (int j = 0; j < n; j++)
            {   
                if(grid[i][j] == 0)
                {
                    ans = max(dfs(i, j, n, 0, grid, vis), ans);
                }
            }
        }
        if(ans == INT32_MAX or ans == INT32_MIN) 
        {
            return -1;
        }
        return ans;
    }
};