class Solution 
{
public:
    bool isIsomorphic(string str1, string str2) 
    {   
        int n = str1.size();
        unordered_map<char, char> mp;
        unordered_set<char> s;
        for(int i = 0; i < n; i++)
        {   
            if(mp.find(str1[i]) != mp.end() and mp[str1[i]] != str2[i]) return false;
            mp[str1[i]] = str2[i];
        }
        for(auto keyVal : mp)
        {   
            if(s.find(keyVal.second) != s.end())
            {
                return false;
            }
            s.insert(keyVal.second);
        }
        return true;
    }
};