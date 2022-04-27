class Solution 
{
private:

    bool isValid(int i, int j, vector<vector<int>> &grid)
    {
        if(i >= 0 and i < grid.size() and j >= 0 and j < grid[0].size())
        {
            if(grid[i][j] == 0) return true;
        }
        return false;
    }

    bool putVal(int val, int i, int j, vector<vector<int>> &grid, char dir = 'r')
    {   
        if(isValid(i, j, grid) == false)
        {
            return false;
        }

        bool flag;
        grid[i][j] = val;
        if(dir == 'r')
        {   
            flag = true;
            flag = putVal(val + 1, i, j + 1, grid, 'r');

            if(flag == false)
            {
                flag = putVal(val + 1, i + 1, j, grid, 'd');
            }
        }
        else if(dir == 'd')
        {
            flag = true;
            flag = putVal(val + 1, i + 1, j, grid, 'd'); // down

            if(flag == false)
            {
                flag = putVal(val + 1, i, j - 1, grid, 'l'); // left
            }
        }
        else if(dir == 'l')
        {
            flag = true;
            flag = putVal(val + 1, i, j - 1, grid, 'l'); // left
            if(flag == false)
            {
                flag = putVal(val + 1, i - 1, j, grid, 'u'); // up
            }            
        }
        else // up
        {   
            flag = true;
            flag = putVal(val + 1, i - 1, j, grid, 'u');
            if(flag == false)
            {
                flag = putVal(val + 1, i, j + 1, grid, 'r'); // right
            }
        }
        return true;
    }

public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>> grid(n, vector<int>(n, 0));
        putVal(1, 0, 0, grid); 
        return grid;
    }
};