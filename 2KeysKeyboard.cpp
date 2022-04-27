class Solution 
{
private:
    int help(int charCntOnScr, int charCntOnClip, int n, bool flag)
    {
        if(charCntOnScr == n) return 0;
        if (charCntOnScr > n) return 10000;  // INT32_MAX

        if(charCntOnClip == 0)
        {
            return 1 + help(charCntOnScr, charCntOnScr, n, false);
        }
        else if(flag == true)
        {
            return min(1 + help(charCntOnScr, charCntOnScr, n, false), 1 + help(charCntOnScr + charCntOnClip, charCntOnClip, n, true));
        } 
        return 1 + help(charCntOnScr + charCntOnClip, charCntOnClip, n, true);   
    }   

public:
    int minSteps(int n) 
    {
        return help(1, 0, n, true);
    }
};