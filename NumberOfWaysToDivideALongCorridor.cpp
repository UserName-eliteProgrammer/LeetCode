class Solution 
{
private:
    int **dp;
    int MOD = 1e9 + 7;
    
    int help(string &s, int seats = 0, int index = 0)
    {
        if(index == s.size())
        {
            if(seats == 2) return 1;
            return 0;
        }
        if(dp[index][seats] != -1) return dp[index][seats];

        if(s[index] == 'S')
        {
            if(seats == 2)
            {
                return dp[index][seats] = help(s, 1, index + 1) % MOD;
            }
            else
            {
                return dp[index][seats] = help(s, seats + 1, index + 1) % MOD;
            }
        }
        else
        {
            if(seats == 2)
            {
                return dp[index][seats] = (help(s, 0, index + 1)  % MOD) + (help(s, seats, index + 1)  % MOD)  % MOD;
            }
            else
            {
                return dp[index][seats] = help(s, seats, index + 1) % MOD;
            }
        }
        return 0;
    }
    
public:
    int numberOfWays(string corridor) 
    {   
        dp = new int*[corridor.size()];
        for (int i = 0; i < corridor.size(); i++)
        {
            dp[i] = new int[3]();
            for(int j = 0; j < 3; j++)
            {
                dp[i][j] = -1;
            }
        }
        return help(corridor);
    }
};