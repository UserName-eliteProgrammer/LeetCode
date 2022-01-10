class Solution 
{    
    vector<vector<int>> ans;
public:
    void help(vector<int> &nums, vector<int> &subset, int index)
    {
        if(index == nums.size())
        {
            ans.push_back(subset);
            return;
        }

        subset.push_back[nums[index]];
        help(nums, subset, index + 1);
        subset.pop_back();
        help(nums, subset, index + 1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<int> subset;
        help(nums, subset, 0);
        return ans;
    }
};