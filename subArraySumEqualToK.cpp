#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pb push_back
using namespace std;

// Problem Link --->

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int ans = 0, size = nums.size();
        unordered_map<int, int> mp;
        mp[0]++;

        for (int i = 1; i < size; i++)
        {
            nums[i] = nums[i] + nums[i - 1];
        }
        for (int i = 0; i < size; i++)
        {
            if (mp.find(nums[i] - k) != mp.end())
            {
                ans += mp[nums[i] - k];
            }
            mp[nums[i]]++;
        }
        return ans;
    }
};