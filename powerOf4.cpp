class Solution 
{
public:
    bool isPowerOfFour(int n) 
    {
        if(n <= 0) return false;
       
        for(int i = 0; i < 32; i+= 2)
        {
            if((1 << i) == n) return true;
            if((1 << i) > n) break;
        }
        return false;
    }
};