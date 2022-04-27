class Solution 
{
private:
    int getDis(int i, int j, vector<vector<int>>& dp)
    {   
        int ans = INT16_MAX;
        int x[] = {-1, 1, 0, 0};
        int y[] = {0, 0, -1, 1};
        for(int k = 0; k < 4; k++)
        {
            int newI = y[k] + i, newJ = x[k] + j;
            if(newI >= 0 and newI < dp.size() and newJ >= 0 and newJ < dp[0].size())
            {
                ans = min(ans, dp[newI][newJ] + 1);
            }
        }
        return ans;
    }
    
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) 
    {   
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT16_MAX - 1));
       
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {   
                if(grid[i][j] == 0) dp[i][j] = 0;
                else dp[i][j] = getDis(i, j, dp);
            }
        }
           
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = m - 1; j >= 0; j--)
            {   
                if(grid[i][j] == 0) dp[i][j] = 0;
                else dp[i][j] = getDis(i, j, dp);
            }
        }
        return dp;
    }
};