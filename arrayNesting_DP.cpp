#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pb push_back
using namespace std;

// Problem Link --->

class Solution
{
public:
    int arrayNesting(vector<int> &nums)
    {
        int ans = 0, temp = 0;
        vector<int> dp(nums.size(), -1);
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == -1)
            {
                continue;
            }

            int j = i;
            do
            {
                if (dp[j] != -1)
                {
                    temp = dp[j] + temp;
                    break;
                }
                int prev = j;
                j = nums[j];
                nums[prev] = -1;
                temp++;
            } while (j != i);
            ans = max(ans, temp);
            dp[i] = temp;
            temp = 0;
        }
        return ans;
    }
};