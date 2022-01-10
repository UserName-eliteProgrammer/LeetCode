
class Solution 
{
public:
    unordered_map<char, int> mp;
    bool stringCmp(string s1, string s2)
    {   
        for (int i = 0; i < s1.size() and i < s2.size(); i++)
        {
            int cmp1 = mp[s1[i]];
            int cmp2 = mp[s2[i]];

            if(cmp1 > cmp2)
            {
                return false;
            }
            else if(cmp1 < cmp2)
            {
                return true;
            }
        }

        if(s1.size() > s2.size())
        {
            return false;
        }
        return true;
    }

    bool isAlienSorted(vector<string>& words, string order) 
    {
        int val = 1;
        for (int i = 0; i < order.size(); i++)
        {
            mp[order[i]] = val;
            val++;
        }

        for (int i = 0; i < words.size() - 1; i++)
        {
            if(stringCmp(words[i], words[i + 1]) == false)
            {
                return false;
            }
        }
        return true;
    }
};