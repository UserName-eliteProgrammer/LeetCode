class Solution {
public:
    map<string, int> mp;
    int stringToNumber(string str)
    {   
        int num = 0;
        int j = 0;

        for(int i = str.size() - 1; i >= 0; i--)
        {
            num = num + ((str[i] - '0') * pow(10, j));
            j++;
        }
        return num;
    }
    
    int numDecodings(string s) 
    {
        if(s.size() == 1 and s[0] != '0')
        {
            return 1;
        }
        if(s.size() == 1)
        {
            return 0;
        }
        if(s.size() == 2 and stringToNumber(s) <= 26 and stringToNumber(s) > 0 and s[0] != '0' and s[1] != '0')
        {
            return 2;
        }
        if(s.size() == 2 and s[0] != '0')
        {
            return 1;
        }
        if(mp[s] != 0)
        {
            return mp[s];
        }
        
        int ans = 0;
        for(int i = 0; i <= 1 and i < s.size(); i++)
        {   
            string remaining = s.substr(i + 1);
            if(stringToNumber(s.substr(0, i + 1)) <= 26 and stringToNumber(s.substr(0, i + 1)) > 0 and s[0] != '0')
            {
                ans = ans + numDecodings(remaining);
            }
        }
        return mp[s] = ans;
    }
};