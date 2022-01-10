class Solution 
{
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {   
       int n = nums.size();
       vector<int> prefix(n), postfix(n), ans(n);
       prefix[0] = nums[0];
       postfix[0] = nums[n - 1];
       for(int i = 1; i < n; i++)
       {
            prefix[i] = prefix[i - 1] * nums[i];  
       }
       for(int i = n - 2; i >= 0; i--)
       {
            postfix[n - i - 1] = postfix[n - i - 2] * nums[i];     
       }
        
       ans[0] = postfix[n - 2];
       ans[n - 1] = prefix[n - 2];
       for(int i = 1; i < n - 1; i++)
       {   
           ans[i] = prefix[i - 1] * postfix[n - i - 2];
       }
       return ans;
    }
};