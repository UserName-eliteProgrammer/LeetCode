class Solution 
{
private :
    int binarySearch(vector<pair<int, int>> &arr, int target)
    {
        int l = 0, h = arr.size() - 1, index = -1;
        while(l <= h)
        {
            int m = h - ((h - l) / 2);
            if(arr[m].first == target) return m;
            else if(arr[m].first > target)
            {
                index = m;
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
    int specialArray(vector<int>& nums) 
    {   
        int maxi = nums[0];
        map<int, int, greater<int>> mp1, mp2;
        for (int i = 0; i < nums.size(); i++)
        {
            mp1[nums[i]]++;
            maxi = max(maxi, nums[i]);
        }

        int sum = 0;
        for(auto p : mp1)
        {   
            sum += p.second;
            mp2[p.first] = sum;
        }

        vector<pair<int, int>> arr;
        for(auto p : mp2)
        {
            arr.push_back({p.first, p.second});
        }
        reverse(arr.begin(), arr.end());
        
        for(int i = 0; i <= maxi; i++)
        {   
            int index = binarySearch(arr, i);
            if(index != -1)
            {
                if(i == arr[index].second) 
                {
                    return i;
                }
            }
        }
        return -1;
    }
};