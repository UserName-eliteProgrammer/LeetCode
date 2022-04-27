class Solution 
{
private:
int *dp;
int help(vector<int> &dist, int pos, int n)
{   
    if(pos == n - 1)
    {
        return 0;
    }
    if(dp[pos] != 0) return dp[pos];

    int ans = INT32_MAX - 1;
    for (int i = 1; i <= dist[pos]; i++)
    {   
        if(i + pos >= n) break;
        ans = min(ans, 1 + help(dist, pos + i, n));
    }
    return dp[pos] = ans;
}

public:
    int jump(vector<int>& nums) 
    {
        int n = nums.size();
        dp = new int[n]();
        return help(nums, 0, n);
    }
};