class Solution 
{
public:
    bool canJump(vector<int>& arr) 
    {   
        int n = arr.size();
        vector<bool> dp(n, false);
        dp[0] = true;
        
        for(int i = 1; i < n; i++)
        {
            for(int j = i - 1; j >= 0; j--)
            {
                if(dp[j] == true and i - j <= arr[j])
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n - 1];
    }
};