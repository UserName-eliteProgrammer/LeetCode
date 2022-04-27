class Solution 
{
public:
    
    // val = -1 -> can buy
    // val represents what is value of stock that was buyed.
    
    int help(vector<int> &arr, vector<unordered_map<int, int>> &dp, int index = 0, int val = -1)
    {
        if(index == arr.size())
        {   
            if(val != -1) return -val;
            return 0;
        }
        
        if(dp[index].find(val) != dp[index].end())
        {
            return dp[index][val];
        }
        
        if(val != -1 and arr[index] > val) // currently have a stock. so, i have choice to sell or not but i cannot buy
        {   
             int ans1 = help(arr, dp, index + 1, val); // not sell
             int ans2 = (arr[index] - val) + help(arr, dp, index + 1, -1); // sell
           return dp[index][val] = max(ans1, ans2);     
        }
        if(val == -1) // i have choice to buy or not
        {   
            int ans1 = help(arr, dp, index + 1, arr[index]); // buy
            int ans2 = help(arr, dp, index + 1, -1); // not buy
            return dp[index][val] = max(ans1, ans2);
        }  
        return 0;
    }
    
    int maxProfit(vector<int>& prices) 
    {   
        vector<unordered_map<int, int>> dp(prices.size());
        return help(prices, dp);
    }
};