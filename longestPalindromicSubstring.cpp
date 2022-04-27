class Solution 
{
private:
    int i = 0, j = 0;
    int **dp;
    bool help(string &str, int s, int e)
    {   
        if(s == e)
        {
            return true;
        }
        if(s == e - 1)
        {
            if(str[s] == str[e])
            {   
                if(j - i < e - s) 
                {
                    i = s;
                    j = e;
                }
                return true;    
            } 
            return false;
        }
        if(dp[s][e] != -1)
        {
            return dp[s][e];
        }
        
        bool flag = false;
        if(str[s] == str[e])
        {
            flag = help(str, s + 1, e - 1);
            if(flag == true)
            {
                if(j - i < e - s) 
                {
                    i = s;
                    j = e;
                }
                return dp[s][e] = true;
            }
        }
        if(flag == false)
        {
            help(str, s + 1, e);
            help(str, s, e - 1);
        }
        return dp[s][e] = false;
    }

public:
    string longestPalindrome(string s) 
    {
        string ans;
        dp = new int*[s.size()];
        for (int i = 0; i < s.size(); i++)
        {
            dp[i] = new int[s.size()];
            for (int j = 0; j < s.size(); j++)
            {
                dp[i][j] = -1;
            }
        }

        help(s, 0, s.size() - 1);
        
        for(int k = i; k <= j; k++)
        {
            ans.push_back(s[k]);
        }
        return ans;
    }
};