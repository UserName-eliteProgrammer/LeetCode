class Solution 
{
private:
    int binarySearch1(vector<int> &arr, int target)
    {
        int l = 0, h = arr.size() - 1, index = -1;
        while(l <= h)
        {
            int m = (h - (h - l) / 2);
            if(arr[m] == target)
            {
                index = m;
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
        return index;
    }

    int binarySearch2(vector<int> &arr, int target)
    {
        int l = 0, h = arr.size() - 1, index = -1;
        while(l <= h)
        {
            int m = (h - (h - l) / 2);
            if(arr[m] == target)
            {
                index = m;
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
        return index;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {   
        vector<int> ans(2);
        ans[0] = binarySearch1(nums, target);
        ans[1] = binarySearch2(nums, target);
        return ans;
    }
};