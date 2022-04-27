class Solution 
{
public:
    int singleNumber(vector<int>& arr) 
    {   
        int n = arr.size(), ans = 0;
        for(int i = 0; i < 32; i++)
        {   
            int cnt = 0;
            for(int j = 0; j < n; j++)
            {
                if((1 << i) & arr[j])
                {
                    cnt++;
                }
            }
            
            if(cnt % 3)
            {
                ans = ans | (1 << i);
            }
        }
        return ans;
    }
};