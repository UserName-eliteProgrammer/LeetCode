class Solution 
{   
    private void intialize(int[] dp)
    {
        for(int i = 2; i < dp.length; i++)
        {
            dp[i] = Integer.MAX_VALUE;
        }
    }
    
    public int numSquares(int n) 
    {
        int [] dp = new int[n + 1];
        dp[0] = 0; 
        dp[1] = 1;
        intialize(dp);
        
        for(int i = 2; i <= n; i++)
        {
            for(int j = 1; j * j <= i; j++)
            {   
                if (j * j == i)
                {
                    dp[i] = 1;
                    break;
                }
                dp[i] = Math.min(dp[i], dp[j * j] + dp[i - (j * j)]);
            }
        }
        return dp[n];
    }
}