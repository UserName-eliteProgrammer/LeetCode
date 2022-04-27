class Solution 
{
private:
    int *dp;
    int help(int n)
    {
        if(n == 0)
        {
            return 0;
        }
        if(dp[n] != 0) return dp[n];
        
        int ans = INT32_MAX;
        for(int i = 1; i * i <= n; i++)
        {
            ans = min(ans, 1 + help(n - (i * i)));
        }
        return dp[n] = ans;
    }
    
public:
    int numSquares(int n) 
    {
        dp = new int[n + 1]();
        return help(n);
    }
};