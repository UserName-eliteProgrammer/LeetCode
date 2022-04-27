class Solution 
{
private:
    vector<vector<int>> ans;
    void help(vector<int>& arr, int index = 0)
    {
        if(index == arr.size())
        {
            ans.push_back(arr);
            return;
        }

        set<int> s;
        for (int i = index; i < arr.size(); i++)
        {
            if(s.find(arr[i]) != s.end()) continue;
            
            s.insert(arr[i]);
            swap(arr[index], arr[i]);
            help(arr, index + 1);
            swap(arr[index], arr[i]);
        }
        return;
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        help(nums);
        return ans;
    }
};