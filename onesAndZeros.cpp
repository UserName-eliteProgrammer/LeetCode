class Solution 
{
private:
    vector<pair<int, int>> count;
    int help(int index, int n, int m, vector<vector<vector<int>>> &dp)
    {   
        if(index == count.size())
        {   
            return 0;
        }
        if(dp[index][n][m] != -1) return dp[index][n][m];
        
        int ans1 = 0, ans2 = 0;
        if(n >= count[index].first and m >= count[index].second)
        {
            ans1 = 1 + help(index + 1, n - count[index].first, m - count[index].second, dp);   
        }
        ans2 = help(index + 1, n, m, dp);
        return dp[index][n][m] = max(ans1, ans2);
    }
    
public:
    int findMaxForm(vector<string>& arr, int m, int n) 
    {   
        vector<vector<vector<int>>> dp(arr.size(), vector<vector<int>> (m + 1, vector<int>(n + 1, -1)));
        for(auto s : arr)
        {   
            int cntZero = 0;
            for(int i = 0; i < s.size(); i++)
            {
                if(s[i] == '0') cntZero++;
            }
            count.push_back({cntZero, s.size() - cntZero});
        }
        return help(0, m, n, dp);
    }
};