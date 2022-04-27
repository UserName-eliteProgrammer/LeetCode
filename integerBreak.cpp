class Solution 
{
private:
    int superHelpHelper(int n, int index)
    {
        if(n == 0) return 1;
        if(n < 0) return 0;
        
        return index * superHelpHelper(n - index, index);
    }

    int superHelper(int n)
    {   
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {   
            if(n % i) continue;
            ans = max(ans, superHelpHelper(n, i));
        }
        return ans;
    }
    
    int help(int n)
    {   
        int ans = 0;
        for(int i = 1; i <= n / 2; i++)
        {
            ans = max(ans, superHelper(i) * superHelper(n - i));
        }
        return ans;
    }
        
public:
    int integerBreak(int n) 
    {   
       return help(n);
    }
};