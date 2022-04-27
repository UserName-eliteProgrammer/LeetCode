class Solution 
{
private:
    vector<vector<int>> ans;
    void help(vector<int> &arr, int index = 0)
    {
        if(index == arr.size())
        {
            ans.push_back(arr);
            return;
        }

        for (int i = index; i < arr.size(); i++)
        {
            swap(arr[index], arr[i]);
            help(arr, index + 1);
            swap(arr[index], arr[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        help(nums);
        return ans;
    }
};