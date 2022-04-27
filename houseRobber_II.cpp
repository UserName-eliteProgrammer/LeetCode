// bottom up

class Solution 
{
private:
    int help(vector<int> &arr)
    {   
        int n = arr.size();
        vector<int> dp(n);
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);

        for (int i = 2; i < n; i++)
        {   
            dp[i] = max(arr[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[n - 1];
    }

public:
    int rob(vector<int>& nums) 
    {   
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        int n = nums.size();
        vector<int> temp1(n - 1), temp2(n - 1);
        for (int i = 0; i < n - 1; i++)
        {
            temp1[i] = nums[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            temp2[i] = nums[i + 1];
        }
        return max(help(temp1), help(temp2));
    }
};



// top down

class Solution 
{
private:
    int *dp;
    int help(vector<int> &arr, int n)
    {
        if(n < 0) return 0;
        if(dp[n] != 0) return dp[n];
        return dp[n] = max(arr[n] + help(arr, n - 2), help(arr, n - 1));
    }

public:
    int rob(vector<int>& nums) 
    {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);

        int n = nums.size();
        vector<int> temp1(n - 1), temp2(n - 1);
        dp = new int[n - 1]();
        for (int i = 0; i < n - 1; i++)
        {
            temp1[i] = nums[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            temp2[i] = nums[i + 1];
        }
        
        int ans1 = help(temp1, n - 2);
        delete[] dp;
        dp = new int[n - 1]();
        int ans2 = help(temp2, n - 2);
        return max(ans1, ans2);
    }
};