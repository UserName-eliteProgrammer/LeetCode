class Solution 
{
public:
    int countKDifference(vector<int>& nums, int k) 
    {
        int ans = 0;
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            if(mp.find(-k + nums[i]) != mp.end())
            {
                ans = ans + mp[-k + nums[i]];
            }
            if(mp.find(k + nums[i]) != mp.end())
            {
                ans = ans + mp[k+nums[i]];
            }
            mp[nums[i]]++;
        }
        return ans;
    }
};