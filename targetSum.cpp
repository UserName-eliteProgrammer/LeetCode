#include<bits/stdc++.h>
using namespace std;

int help(vector<int> &arr, int target, int sum, int size)
{
	if(size == 0 and sum == target)
	{
		return 1;
	}
	if(size == 0)
	{
		return 0;
	}

	int ans1 = help(arr, target, sum + arr[size - 1], size - 1);
	int ans2 = help(arr, target, sum - arr[size - 1], size - 1);
	return ans1 + ans2;
}

int findTargetSumWays(vector<int>& nums, int target) 
{
	return help(nums, target, 0, nums.size());
}

int main()
{

}