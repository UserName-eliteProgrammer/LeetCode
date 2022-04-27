class Solution 
{
private:
    vector<vector<int>> ans;
    vector<int> temp;
    
    void help(vector<int>& candidates, int index, int currSum, int target)
    {
        if(currSum == target)
        {   
            ans.push_back(temp);
            return;
        }
        if (currSum > target)
        {   
            return;
        }

        for (int i = index; i < candidates.size(); i++)
        {   
            temp.push_back(candidates[i]);
            help(candidates, i, currSum + candidates[i], target);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        help(candidates, 0, 0, target);
        return ans;
    }
};