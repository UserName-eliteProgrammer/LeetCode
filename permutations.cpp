class Solution 
{
private:
    vector<vector<int>> ans;
    vector<int> temp;
    unordered_set<int> s;

    void help(vector<int> &arr, vector<int> &temp)
    {   
        if(temp.size() == arr.size())
        {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < arr.size(); i++)
        {   
            if(s.find(arr[i]) == s.end()) continue;

            temp.push_back(arr[i]);
            s.erase(arr[i]);
            help(arr, temp);
            temp.pop_back();
            s.insert(arr[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        for (int i = 0; i < nums.size(); i++)
        {
            s.insert(nums[i]);
        }
        help(nums, temp);
        return ans;
    }
};