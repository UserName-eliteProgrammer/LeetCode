bool cmp(vector<int> v1, vector<int> v2)
{
    if(v1[0] < v2[0]) return true;
    return false;
}

class Solution 
{
private:
    vector<vector<int>> ans;

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end(), cmp);
        ans.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] <= ans[ans.size() - 1][1] and intervals[i][1] > ans[ans.size() - 1][1])
            {
                ans[ans.size() - 1][1] = intervals[i][1];
            }
            else if(intervals[i][0] > ans[ans.size() - 1][1])
            {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};