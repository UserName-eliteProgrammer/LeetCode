class Solution 
{
public:
    vector<vector<int>> ans;
    void help(int k, int n, int currSum, int totalNum, vector<int> &temp, int index)
    {
        if(totalNum == k)
        {
            if(currSum == n)
            {
                ans.push_back(temp);               
            }
            return;
        }
        for(int i = index; i <= 9; i++)
        {   
            temp.push_back(i);
            help(k, n, currSum + i, totalNum + 1, temp, i + 1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) 
    {   
        vector<int> temp;
        help(k, n, 0, 0, temp, 1);
        return ans;
    }
};