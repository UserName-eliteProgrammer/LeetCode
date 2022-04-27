class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int row = -1, l = 0, h = matrix.size() - 1;
        while(l <= h)
        {   
            int m = (l + h) / 2;
            if(matrix[m][0] <= target)
            {
                row = m;
                l = m + 1;
            }
            else
            {
                h = m - 1;
            }
        }
        
        if(row == -1) return false;
        
        l = 0, h = matrix[0].size() - 1;
        while(l <= h)
        {
            int m = (l + h) / 2;
            if(matrix[row][m] == target) return true;
            else if(matrix[row][m] > target)
            {
                h = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        return false;
    }
};