class Solution 
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        priority_queue<pair<int, int>> q;
        vector<int> ans;
        int i = 0, j = 0;
        while(j < nums.size() and j < k)
        {   
            q.push({nums[j], j});
            j++;
        }
        j--;
        ans.push_back(q.top().first);
        
        while(j < nums.size())
        {   
            if(q.top().second <= i)
            {
                while(q.top().second <= i and not q.empty())
                {
                    q.pop();
                }
            }
            i++;
            j++;
            if(j == nums.size()) break;
            q.push({nums[j], j});
            ans.push_back(q.top().first);
        }
        return ans;
    }
};