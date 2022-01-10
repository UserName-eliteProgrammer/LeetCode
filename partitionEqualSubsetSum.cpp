class Solution 
{
public:
    bool check(vector<int>& nums, int sumTillNow, int total, int size)
    {
        if(size == 0)
        {
            return false;
        }
        if(total - sumTillNow == sumTillNow) 
        {
            return true;
        }
        
        if(check(nums, sumTillNow + nums[size - 1], total, size - 1)) return true;
        if(check(nums, sumTillNow, total, size - 1)) return true;
        return false;
    }

    bool canPartition(vector<int>& nums) 
    {
        int sum = 0, size = nums.size();
        for (int i = 0; i < size; i++)
        {
            sum += nums[i];        
        }
        if(sum & 1)
        {
            return false;
        }
        return check(nums, 0, sum, size);    
    }
};