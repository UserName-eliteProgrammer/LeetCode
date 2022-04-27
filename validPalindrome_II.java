class Solution 
{
    public boolean validPalindrome(String s) 
    {   
        int suspect1 = -1, suspect2 = -1;
        for(int i = 0; i < (s.length()) / 2; i++)
        {
            if(s.charAt(i) != s.charAt(s.length() - i - 1))
            {
                suspect1 = i;
                suspect2 = s.length() - i - 1;
                break;
            }
        }
        
        if(suspect1 != -1)
        {
            int i = suspect1 + 1, j = suspect2;
            while(i <= j)
            {
                if(s.charAt(i) != s.charAt(j))
                {
                    break;
                }
                i++;
                j--;
            }
            
            if(i <= j)
            {
                i = suspect1; j = suspect2 - 1;
                while(i <= j)
                {
                    if(s.charAt(i) != s.charAt(j))
                    {
                        return false;
                    }
                    i++;
                    j--;
                }  
            }
        }
        return true;
    }
}