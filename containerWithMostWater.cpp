class Solution 
{
public:
    int maxArea(vector<int>& arr) 
    {
        int ans = 0, i = 0, j = arr.size() - 1;
        while(i <= j)
        {
            ans = max(ans, (j - i) * min(arr[i], arr[j]));
            if(arr[i] < arr[j]) i++;
            else j--;
        }
        return ans;
    }
};