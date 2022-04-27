class Solution 
{
private:
    bool isBitSet(int i ,int num)
    {
        if(num & (1 << i))
        {
            return true;
        }
        return false;
    }

public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        int mainXor = 0;
        vector<int> ans(2, 0);
        for(int i = 0; i < nums.size(); i++)
        {
            mainXor = mainXor xor nums[i];
        }
        
        for(int i = 0; i < 32; i++)
        {
            if(isBitSet(i, mainXor))
            {
                for(int j = 0; j < nums.size(); j++)
                {
                    if(isBitSet(i, nums[j]))
                    {
                        ans[0] = ans[0] xor nums[j];       
                    }
                }
                break;       
            }
        }
        ans[1] = ans[0] xor mainXor;
        return ans;
    }
};