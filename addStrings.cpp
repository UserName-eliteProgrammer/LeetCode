class Solution 
{
public:
    string addStrings(string num1, string num2) 
    {
        int carry = 0;
        int i = num1.size() - 1, j = num2.size() - 1;
        string ans;

        while(i >= 0 and j >= 0)
        {
            int temp = (num1[i] - '0') + (num2[j] - '0');
            if(carry != 0)
            {
                temp += carry;
                carry = 0;
            }

            string charSum = to_string(temp);
            if(temp >= 10)
            {
                carry = charSum[0] - '0';
                ans.push_back(charSum[1]);
            }
            else
            {   
                ans.push_back(charSum[0]);
            }
            
            i--;
            j--;
        }
        
        while(j >= 0)
        {   
           int temp = num2[j] - '0';
           if(carry)
           {
               temp += carry;
               carry = 0;
           }
            
           string charSum = to_string(temp);
           if(temp >= 10)
           {
                carry = charSum[0] - '0';
                ans.push_back(charSum[1]);
           }
           else
           {   
                ans.push_back(charSum[0]);
           }
           j--;
        }

        while(i >= 0)
        {
           int temp = num1[i] - '0';
           if(carry)
           {
               temp += carry;
               carry = 0;
           }
            
           string charSum = to_string(temp);
           if(temp >= 10)
           {
                carry = charSum[0] - '0';
                ans.push_back(charSum[1]);
           }
           else
           {   
                ans.push_back(charSum[0]);
           }
           i--;
        }
        
        if(carry)
        {
            ans.push_back(carry + '0');
            carry = 0;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};