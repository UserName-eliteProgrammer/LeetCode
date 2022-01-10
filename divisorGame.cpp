class Solution 
{
public:
    bool ans = true;
    int help(int n, int player)
    {
        if(n == 1)
        {
            return player;
        }
        for (int i = 1; i < n; i++)
        {   
            if(n % i != 0) continue;
            if(help(n - i, not player) == 0)
            {
                ans = false;
                return 0;
            }
        }
        return 1;
    }
    
    bool divisorGame(int n) 
    {   
        help(n, 0);
        return ans;
    }
};