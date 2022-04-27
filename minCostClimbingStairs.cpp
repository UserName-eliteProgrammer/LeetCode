class Solution 
{
private:
    map<int, int> dp;
    int help(vector<int>& cost, int index)
    {
        if(index >= cost.size())
        {
            return 0;
        }
        if(dp.find(index) != dp.end())
        {
            return dp[index];
        }
        return dp[index] = cost[index] + min(help(cost, index + 1), help(cost, index + 2));
    }

public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int ans1 = help(cost, 0);
        dp.clear();
        int ans2 = help(cost, 1);
        return min(ans1, ans2);     
    }
};




// bottom up
class Solution 
{
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        vector<int> dp(cost.size(), 0);
        for (int i = 2; i < dp.size(); i++)
        {
            dp[i] = min(cost[i - 1] + dp[i - 1], cost[i - 2] + dp[i - 2]);
        }
        return min(cost[cost.size() - 1] + dp[cost.size() - 1], cost[cost.size() - 2] + dp[cost.size() - 2]);
    }
};