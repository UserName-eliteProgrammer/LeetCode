class Solution 
{
private:
    int ans = 0;
    bool isValid(vector<vector<bool>> &grid, int row, int column)
    {
        // for column
        for (int i = row - 1; i >= 0; i--)
        {
            if(grid[i][column] == true) return false;
        }

        // left diagonal
        for(int i = row - 1, j = column - 1; i >= 0 and j >= 0; i--, j--)
        {
            if(grid[i][j] == true) return false;
        }

        // right diagonal
        for(int i = row - 1, j = column + 1; i >= 0 and j < grid.size(); i--, j++)
        {
            if(grid[i][j] == true) return false;
        }
        return true;
    }
    void help(vector<vector<bool>> &grid, int currRow)
    {   
        if(currRow == grid.size())
        {   
            ans++;
            return;
        }
        for (int i = 0; i < grid.size(); i++)
        {
            if(isValid(grid, currRow, i) == true)
            {
                grid[currRow][i] = true;
                help(grid, currRow + 1);
                grid[currRow][i] = false;
            }
        }
        return;
    }
    
public:
    int totalNQueens(int n) 
    {   
        vector<vector<bool>> grid(n, vector<bool>(n, false));
        help(grid, 0);
        return ans;
    }
};