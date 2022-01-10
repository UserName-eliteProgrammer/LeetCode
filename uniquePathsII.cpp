#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pb push_back
using namespace std;

int help(vector<vector<int>> &grid, int i, int j, int m, int n, vector<vector<int>> &dp)
{
    if(i == m - 1 and j == n - 1 and grid[i][j] == 0)
    {
        return 1;
    }
    if(i == m - 1 and j == n - 1 and grid[i][j] == 1)
    {
        return 0;
    }

    if(grid[i][j] == 1)
    {
        return 0;
    }

    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int ans1 = 0, ans2 = 0;
    if (i < m - 1)
    {
        ans1 = help(grid, i + 1, j, m, n, dp);
    }
    if(j < n - 1)
    {
        ans2 = help(grid, i, j + 1, m, n, dp);
    }
    return dp[i][j] = ans1 + ans2;
}

int uniquePathsWithObstacles(vector<vector<int>> &Grid)
{
    int m, n;
    m = Grid.size();
    n = Grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return help(Grid, 0, 0, m, n ,dp);
}

int main()
{
}