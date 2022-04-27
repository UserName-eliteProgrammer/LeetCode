#define ll long long int

class Solution 
{
private:
	bool binarySearch1(vector<ll> &arr, ll target)
	{
		int l = 0, h = arr.size() - 1;
		while(l <= h)
		{	
			int m = (l + h) / 2;
			if(arr[m] >= target) return true;
			else if(arr[m] < target) l = m + 1;
		}
		return false;
	}

	bool binarySearch2(vector<ll> &arr, ll target)
	{
		int l = 0, h = arr.size() - 1;
		while(l <= h)
		{
			int m = (l + h) / 2;
			if(arr[m] <= target) return true;
			else if(arr[m] > target) h = m - 1;
		}
		return false;
	}

public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) 
    {	
    	int ans = 0, n = differences.size();
    	vector<ll> arr(n, differences[0]);
  		for (int i = 1; i < n; i++)
  		{
  			arr[i] = differences[i] + arr[i - 1];
  		}
  		sort(arr.begin(), arr.end());

  		for (int i = lower; i <= upper; i++)
  		{
  			bool flag1 = binarySearch1(arr, (upper - i + 1));
  			bool flag2 = binarySearch2(arr, (lower - i - 1));
  			if(flag1 == false and flag2 == false)
  			{
  				ans++;
  			}
  		}
  		return ans;     
    }
};