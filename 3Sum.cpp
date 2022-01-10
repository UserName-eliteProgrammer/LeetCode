class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {   
        vector<vector<int>> ans;
        ans.reserve(3000);
        unordered_map<int, int>mp;
        set<vector<int>> s;
        if(nums.size() < 3)
        {
            return ans;
        }
        
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]] = i;
        }
        
        for(int i = 0; i < nums.size() - 2; i++)
        {   
            if(i > 0 and nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < nums.size() - 1; j++)
            {   
                int val = nums[i] + nums[j];
                if(mp.count(-val) and mp[-val] > i and mp[-val] > j)
                {   
                    vector<int> temp = {nums[i], nums[j], nums[mp[-val]]};
                    sort(temp.begin(), temp.end());
                    if(s.count(temp) == 0)
                    {   
                        ans.push_back(temp);
                        s.insert(temp);    
                    }
                }
            }
        }
        return ans;
    }
};