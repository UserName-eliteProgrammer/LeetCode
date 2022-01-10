class Solution 
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        unordered_set<int> s;
        int i = 0, j = 0;
        while(j <= k and j < nums.size())
        {   
            if(s.count(nums[j]))
            {
                return true;
            }
            s.insert(nums[j]);
            j++;
        }
        while(j < nums.size())
        {
            s.erase(nums[i]);
            if(s.count(nums[j]))
            {
                return true;
            }
            s.insert(nums[j]);
            j++;
            i++;    
        }
        return false;
    }
};