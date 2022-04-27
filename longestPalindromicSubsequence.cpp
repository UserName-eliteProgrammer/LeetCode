class Solution 
{
private: 
    int help(string &s, int i, int j, vector<vector<int>> &dp)
    {
        if(i <= j)
        {   
            if(dp[i][j] != -1)
            {
                return dp[i][j];
            }
            
            if(s[i] == s[j] and i != j)
            {
                return dp[i][j] = 2 + help(s, i + 1, j - 1, dp);
            }
            else if(s[i] == s[j])
            {
                return dp[i][j] = 1 + help(s, i + 1, j - 1, dp);
            }
            return dp[i][j] = max(help(s, i + 1, j, dp), help(s, i, j - 1, dp));
        }
        return 0;
    }
    
public:
    int longestPalindromeSubseq(string s) 
    {   
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        if(s.size() == 0 or s.size() == 1)
        {
            return s.size();
        }
        return help(s, 0, s.size() - 1, dp);    
    }
};