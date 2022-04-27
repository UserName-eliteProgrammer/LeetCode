class Solution 
{
private:
    bool help(int n)
    {   
        if(n <= 0) return false;
        
        int setBits = 0;
        for(int i = 0; i < 32; i++)
        {
            if((1 << i) & n)
            {
                setBits++;
            }
            if(setBits > 1)
            {
                return false;
            }
        }
        return true;
    }
    
public:
    bool isPowerOfTwo(int n) 
    {   
        return help(n);
    }
};