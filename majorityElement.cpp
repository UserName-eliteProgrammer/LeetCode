#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        unordered_map<int, int> mp;
        int size = nums.size(), ans;
        
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]] > size / 2) ans = nums[i];
        }
        return ans;
    }
};

int main()
{

}