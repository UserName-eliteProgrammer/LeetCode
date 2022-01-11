class Solution 
{
public:
    int getSum(int a, int b) 
    {
        bool carry = false;
        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            if(a & (1 << i) and b & (1 << i))
            {   
                if(carry == true)
                {
                    ans = ans | (1 << i);
                }
                carry = true;
            }
            else if(a & (1 << i) or b & (1 << i))
            {
                if(carry == false)
                {
                    ans = ans | (1 << i);
                }
            }
            else
            {      
                if(carry == true)
                {
                    carry = false;
                    ans = ans | (1 << i);
                }
            }
        }
        return ans;
    }
};