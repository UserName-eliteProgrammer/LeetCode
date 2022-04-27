class Solution 
{
public:
    int help(vector<int>& arr, int *dp, int target)
    {   
        if(target == 0) return 1;
        if(dp[target] != -1) return dp[target];
            
        int total = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i] <= target)
            {
                total += help(arr, dp, target - arr[i]);
            }
        }
        return dp[target] = total;
    }
    
    int combinationSum4(vector<int>& nums, int target) 
    {   
        int *dp = new int[target + 1];
        memset(dp, -1, sizeof(int) * (target + 1));
        return help(nums, dp, target);  
    }
};