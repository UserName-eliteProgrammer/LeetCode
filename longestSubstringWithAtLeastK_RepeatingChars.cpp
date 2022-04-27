class Solution 
{
public:
    int longestSubstring(string s, int k) 
    {   
        int ans = 0;
        unordered_map<char, int> charCount;
        
        for(int totalChars = 1; totalChars <= 26; totalChars++)
        {
            int i = 0, j = 0;
            while(j < s.size())
            {   
                bool flag = true;
                charCount[s[j]]++;
            
                if(charCount.size() > totalChars)
                {
                    while(charCount.size() > totalChars and i <= j)
                    {
                        charCount[s[i]]--;
                        if(charCount[s[i]] == 0)
                        {
                            charCount.erase(s[i]);
                        }
                        i++;
                    }
                }
                
                for(auto p : charCount)
                {
                    if(p.second < k)
                    {   
                        flag = false;
                        break;
                    }
                } 
                if(flag)
                {
                    ans = max(ans, j - i + 1);
                }
                j++;
            }    
            charCount.clear();
        }
        return ans;
    }
};