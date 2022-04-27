class Solution 
{
public:
    
    int help(int s, int e, vector<int>& cuts, vector<vector<int>> &dp)
    {   
        if(dp[s][e] != -1) return dp[s][e];

        int tempAns = INT16_MAX;
        for(int i = 0; i < cuts.size(); i++)
        {   
            if(cuts[i] > s and cuts[i] < e)
            {   
                tempAns = min(tempAns, (e - s) + help(s, cuts[i], cuts, dp) + help(cuts[i], e, cuts, dp));    
            }
        }
        
        if(tempAns == INT16_MAX) return dp[s][e] = 0;
        return dp[s][e] = tempAns;
    }
    
    int minCost(int n, vector<int>& cuts) 
    {   
        vector<vector<int>> dp(1000, vector<int>(1000, -1));
        return help(0, n, cuts, dp);   
    }
};