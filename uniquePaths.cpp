class Solution 
{
private:
    int help(int i, int j, int m, int n,  vector<vector<int>> &dp)
    {   
        if(i >= m or j >= n)
        {
            return 0;
        }
        else if(dp[i][j] != 0)
        {
            return dp[i][j];
        }
        else if(i == m - 1 and j == n - 1)
        {
            return 1;
        }
        return dp[i][j] = help(i + 1, j, m, n, dp) + help(i, j + 1, m, n, dp);
    }
    
public:
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        return help(0, 0, m, n, dp);
    }
};