class Solution 
{
private:
    vector<vector<int>> ans;
    vector<int> temp;
    
    void help(int n, int k, int index = 1)
    {
        if(k == 0) 
        {
            ans.push_back(temp);
            return;
        }
        for(int i = index; i <= n; i++)
        {
            temp.push_back(i);
            help(n, k - 1, i + 1);
            temp.pop_back();
        }
        return;
    }
    
public:
    vector<vector<int>> combine(int n, int k) 
    {   
        help(n, k);
        return ans;
    }
};