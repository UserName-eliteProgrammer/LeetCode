class Solution 
{
private:
    int i = 0, j = 0;
    map<char, int> mpPattern, mpInput;
    vector<int> ans;

    bool isMatched()
    {
        for(auto p : mpInput)
        {
            char key = p.first;
            int val = p.second;
            if(mpPattern.find(key) != mpPattern.end())
            {
                if(mpPattern[key] != mpInput[key])
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    
    void update(char in, char out)
    {
        mpInput[in]++;
        mpInput[out]--;
        if(mpInput[out] == 0) mpInput.erase(out);     
        i++;
        j++;
        return;
    }

public:
    vector<int> findAnagrams(string &input, string &pattern) 
    {   
        
        for (int i = 0; i < pattern.size(); i++)
        {
            mpPattern[pattern[i]]++;
        }

        while(j < pattern.size())
        {
            mpInput[input[j]]++;
            j++;
        }
        while(j < input.size())
        {
            if(isMatched() == true)
            {
                ans.push_back(i);
            }
            update(input[j], input[i]);
        }
        
        if(isMatched() == true)
        {
            ans.push_back(i);
        }
        return ans;
    }
};