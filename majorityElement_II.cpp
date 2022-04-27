class Solution 
{
private:
    vector<int> ans;
public:
    int giveLen(int n)
    {   
        n = n / 3;
        n++;
        return n;
    }
    
    vector<int> majorityElement(vector<int>& nums) 
    {
        int windowSize = giveLen(nums.size()), i = 0, j = 0;
        sort(nums.begin(), nums.end());
        
        while(j + 1 < windowSize)
        {
            j++;
        }
        
        while(j < nums.size())
        {   
            if((nums[i] == nums[j] and ans.size() == 0) or (nums[i] == nums[j] and nums[j] != ans[ans.size() - 1]))
            {
                ans.push_back(nums[i]);
            }
            i++;
            j++;
        }
        return ans;
    }
};