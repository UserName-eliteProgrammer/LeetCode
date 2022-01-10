class Solution 
{
public:
    int findDuplicate(vector<int>& nums) 
    {
        int l = 1, h = nums.size() - 1, ans;
        while(l <= h)
        {
            int mid = (l + h) / 2, cnt = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if(nums[i] <= mid) cnt++;
            }
            if(cnt > mid)
            { 
                h = mid - 1;
                ans = mid;
            }
            else
            { 
                l = mid + 1;
            }
        }
        return ans;
    }
};