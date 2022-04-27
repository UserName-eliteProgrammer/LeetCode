class Solution 
{   
    Integer myInf = Integer.MAX_VALUE;
    private void initialize(int[] nums)
    {   
        for(int i = 0; i < nums.length; i++)
        {
            nums[i] = myInf;
        }
        return;
    }
    
    public int jump(int[] nums) 
    {
        int n = nums.length;
        int[] dist = new int[n];
        initialize(dist);
        dist[0] = 0;
        
        for(int i = 1; i < n; i++)
        {   
            for(int j = i - 1; j >= 0; j--)
            {
                if(i - j <= nums[j])
                {
                    dist[i] = Math.min(dist[i], 1 + dist[j]);
                }
            }
        }
        return dist[n - 1];
    }
}