class Solution 
{
public:
    int search(vector<int>& arr, int target) 
    {
        int l = 0, h = arr.size() - 1;
        while(l <= h)
        {   
            int m = h - ((h - l) / 2);
            if(arr[m] == target)
            {
                return m;
            }
            else if(arr[m] < arr[0])
            {
                if(target > arr[arr.size() - 1])
                {
                    h = m - 1;
                }
                else if(arr[m] > target)
                {
                    h = m - 1;
                }
                else
                {
                    l = m + 1;
                }
            }
            else
            {
                if(target < arr[0])
                {
                    l = m + 1;
                }
                else if(arr[m] > target)
                {
                    h = m - 1;
                }
                else
                {
                    l = m + 1;
                }
            }  
        } 
        return -1;
    }
};