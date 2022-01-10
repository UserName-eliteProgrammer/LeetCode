class Solution 
{
private:
    vector<vector<string>> ans;
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
            ans.push_back(displayGrid(grid));
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

    vector<string> displayGrid(vector<vector<bool>> &grid)
    {   
        int n = grid.size();
        vector<string> temp;

        for (int i = 0; i < n; i++)
        {   
            string s = "";
            for (int j = 0; j < n; j++)
            {   
                if(grid[i][j] == true)
                {
                    s.push_back('Q');
                }
                else
                {   
                    s.push_back('.');
                }              
            }
            temp.push_back(s);               
        }
        return temp;       
    }
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<bool>> grid(n, vector<bool>(n, false));
        help(grid, 0);
        return ans; 
    }
};