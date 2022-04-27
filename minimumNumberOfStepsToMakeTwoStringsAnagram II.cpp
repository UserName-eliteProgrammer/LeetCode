class Solution 
{
public:
    int minSteps(string s, string t) 
    {   
        int ans = 0;
        unordered_map<char, int> mp1, mp2;
        for (int i = 0; i < s.size(); i++)
        {
            mp1[s[i]]++;            
        }
        for (int i = 0; i < t.size(); i++)
        {
            mp2[t[i]]++;            
        }

        for(auto it : mp1)
        {   
            if(mp2.find(it.first) == mp2.end())
            {
                ans += it.second;
            }
            else if(it.second != mp2[it.first])
            {
                ans += abs(it.second - mp2[it.first]);
            }
        }
        for(auto it : mp2)
        {
            if(mp1.find(it.first) == mp1.end())
            {
                ans += it.second;
            }    
        }
        return ans;
    }
};