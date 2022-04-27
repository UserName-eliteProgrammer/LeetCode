class Solution
{
private:
    int help(int amount, int index, vector<int>& coins, vector<vector<int>> &dp)
    {
        if(amount == 0) return 1;
        if(dp[amount][index] != -1) return dp[amount][index];
        
        int ans = 0;
        for(int i = index; i < coins.size(); i++)
        {
            if(amount - coins[i] >= 0)
            {
                ans += help(amount - coins[i], i, coins, dp);
            }
        }
        return dp[amount][index] = ans;
    }
    
public:
    int change(int amount, vector<int>& coins) 
    {   
        vector<vector<int>> dp(5001, vector<int>(301, -1));
        return help(amount, 0, coins, dp);
    }
};