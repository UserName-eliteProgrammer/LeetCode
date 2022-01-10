class Solution 
{
public:
    int knapSack(vector<int>& nums, int n, int sum, int target, vector<vector<int>> &dp)
    {
        if(n == 0) return 0;
        if(sum == target) return 1;
        if(sum > target) return 0;
        if(dp[n][sum] != -1) return dp[n][sum];

        return dp[n][sum] = knapSack(nums, n - 1, sum + nums[n - 1], target, dp) or knapSack(nums, n - 1, sum, target, dp);
    }
    bool canPartition(vector<int>& nums) 
    {   
        int total = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            total += nums[i];
        }
        if(total & 1) return false;
        vector<vector<int>> dp(nums.size() + 1, vector<int>((total / 2) + 1, -1));
        return knapSack(nums, nums.size(), 0, total / 2, dp);
    }
};