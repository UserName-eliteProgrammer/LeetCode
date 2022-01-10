class Solution 
{
public:
    int binarySearch(vector<int> &arr)
    {
        int low = 0, high = arr.size() - 1, index = -1;
        while(low <= high)
        {
            int mid = high - ((high - low) / 2);
            if(arr[mid] < 0)
            {
                index = mid;
                high = mid - 1;
            }
            else if(arr[mid] >= 0)
            {
                low = mid + 1;
            }
        }
        return index;
    }

    int countNegatives(vector<vector<int>>& grid) 
    {   
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++)
        {   
            int index = binarySearch(grid[i]);
            if(index != -1)
            {
                cnt += grid[i].size() - index;
            }
        }
        return cnt;          
    }
};