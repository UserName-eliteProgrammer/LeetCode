class Solution 
{
public:
    vector<string> ans;
    map<char, vector<char>> mp;

    void help(int index, string &digits, string osf)
    {   
        if(index == digits.size())
        {
            ans.push_back(osf);
            return;
        }

        for(auto character : mp[digits[index]])
        {
            help(index + 1, digits, osf + character);
        }
    }

    vector<string> letterCombinations(string digits) 
    {   
        if(digits.size() == 0)
        {
            return ans;
        }
        
        char key = '2';
        char val = 'a';
        while(key <= '9')
        {   
            if(key == '9' or key == '7')
            {
                for (int j = 0; j < 4; j++)
                {
                    mp[key].push_back(val);
                    val++;
                }
            }
            else
            {
                for (int j = 0; j < 3; j++)
                {
                    mp[key].push_back(val);
                    val++;
                }   
            }
            key++;
        }
        
        help(0, digits, "");
        return ans;
    }
};