class Solution 
{
private:
    int binarySearch1(vector<int> &arr, int s, int target)
    {
        int l = s, h = arr.size() - 1, ans = INT32_MAX;
        while(l <= h)
        {
            int m = (l + h) / 2;
            if(arr[m] == target) return arr[m];
            else if(arr[m] > target)
            {
                ans = arr[m];
                h = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        return ans;
    }
    
    int binarySearch2(vector<int> &arr, int s, int target)
    {
        int l = s, h = arr.size() - 1, ans = INT32_MAX;
        while(l <= h)
        {
            int m = (l + h) / 2;
            if(arr[m] == target) return arr[m];
            else if(arr[m] > target)
            {
                h = m - 1;
            }
            else
            {   
                ans = arr[m];
                l = m + 1;
            }
        }
        return ans;
    }
    
    
public:
    int threeSumClosest(vector<int>& arr, int target) 
    {   
        int n = arr.size(), ans = INT16_MAX;
        sort(arr.begin(), arr.end()); 
        for(int i = 0; i < n - 1; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int newtarget = target - (arr[i] + arr[j]);
                int temp1 = binarySearch1(arr, j + 1, newtarget);
                int temp2 = binarySearch2(arr, j + 1, newtarget);
                
                if(temp1 != INT32_MAX and abs(target - ans) > abs(target - (arr[i] + arr[j] + temp1)))
                {
                    ans = arr[i] + arr[j] + temp1;
                }
                if(temp2 != INT32_MAX and abs(target - ans) > abs(target - (arr[i] + arr[j] + temp2)))
                {
                    ans = arr[i] + arr[j] + temp2;
                }   
            }
        }
        return ans;
    }
};