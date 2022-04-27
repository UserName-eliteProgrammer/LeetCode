class Solution
{
public:
    double help1(double num, int x)
    {
        if(x == 1) return num;
        if(x == 0) return 1;
        
        if(x % 2 == 0)
        {
            double ans = help1(num, x / 2);
            return ans * ans;
        }
        else
        {
            double ans = help1(num, x / 2);
            return num * ans * ans;
        }
        return 0;
    }
    
    
    double help2(double num, int x)
    {
        if(x == -1) return 1 / num;
        if(x == 0) return 1;
        
        if(x % 2 == 0)
        {
            double ans = help2(num, x / 2);
            return ans * ans;
        }
        else
        {
            double ans = help2(num, x / 2);
            return (1 / num) * ans * ans;
        }
        return 0;
    }
    
    double myPow(double x, int n) 
    {
        if(n >= 0)
        {
            return help1(x, n);
        }
        return help2(x, n);
    }
};