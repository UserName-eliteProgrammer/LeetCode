class Solution 
{
public:
    string longestCommonPrefix(vector<string>& arr) 
    {
        string ans = "";
        int minLen = INT32_MAX;
        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i].size() < minLen)
            {
                minLen = arr[i].size();
            }
        }
        
        for(int i = 0; i < minLen; i++)
        {
            bool flag = true;
            for(int j = 0; j < arr.size() - 1; j++)
            {  
                if(arr[j][i] != arr[j + 1][i])
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                ans.push_back(arr[0][i]);;
            }
            else if(flag == false)
            {
                break;
            }
        }
        return ans;
    }
};