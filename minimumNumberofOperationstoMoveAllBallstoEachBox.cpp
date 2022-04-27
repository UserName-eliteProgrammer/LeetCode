class Solution 
{
public:
    vector<int> minOperations(string s) 
    {
        int n = s.size(), totalOnes;
        vector<int> ans(n, 0), suffix(n, 0);

        (s[0] == '1') ? totalOnes = 1 : totalOnes = 0;
        for (int i = 1; i < n; i++)
        {
            ans[i] = ans[i - 1] + totalOnes;
            if(s[i] == '1') totalOnes++;
        }

        (s[n - 1] == '1') ? totalOnes = 1 : totalOnes = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            ans[i] = ans[i] + suffix[i + 1] + totalOnes;
            suffix[i] = suffix[i + 1] + totalOnes;
            if(s[i] == '1') totalOnes++;    
        }
        return ans;
    }
};