#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    void moveZeroes(vector<int>& nums) 
    {
       int i = 0, j = 0;
       while(i < nums.size() and j < nums.size())
       {    
       		if(nums[j] == 0)
       		{
       			j++;
       		}	
       		if(nums[i] != 0)
       		{
       			i++;
       		}
            while(j < i)
            {
                j++;
            }

       		if(i < nums.size() and j < nums.size() and nums[i] == 0 and nums[j] != 0)
       		{
       			int temp = nums[i];
       			nums[i] = nums[j];
       			nums[j] = temp;
       		}
       }
       return; 
    }
};

int main()
{

}