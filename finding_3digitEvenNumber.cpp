// brute force

// class Solution 
// {
// public:
//     set<int> ans;
//     int stringToNumber(string s)
//     {
//         int num = 0;
//         for (int i = s.size() - 1; i >= 0; i--)
//         {
//             int temp = s[i] - '0';
//             num = num + (temp * pow(10, s.size() - i - 1));
//         }
//         return num;
//     }

//     int getNum(int num1, int num2, int num3)
//     {
//         string temp1 = "";
//         if(num1 != 0)
//         {
//             temp1 = temp1 + to_string(num1);
//             temp1 = temp1 + to_string(num2);
//             temp1 = temp1 + to_string(num3);
//             return stringToNumber(temp1);
//         }
//         return -1;
//     }
//     void help(vector<int> &digits)
//     {
//         for (int i = 0; i < digits.size(); i++)
//         {
//             if((digits[i] & 1) == 0)
//             {
//                 for (int j = 0; j < digits.size() - 1; j++)
//                 {   
//                     if(j == i) continue;
//                     for (int k = j + 1; k < digits.size(); k++)
//                     {   
//                         if(k == i) continue;
//                         int temp1 = getNum(digits[j], digits[k], digits[i]);
//                         int temp2 = getNum(digits[k], digits[j], digits[i]);
//                         if(temp1 != -1)
//                         {
//                             ans.insert(temp1);
//                         }
//                         if(temp2 != -1)
//                         {
//                             ans.insert(temp2);
//                         }
//                     }
//                 }
//             }
//         }
//     }

//     vector<int> findEvenNumbers(vector<int>& digits) 
//     {
//         vector<int> ans;
//         help(digits);
//         for(auto element : Solution :: ans)
//         {
//             ans.push_back(element);
//         }
//         return ans;     
//     }
// };



// Optimized
class Solution 
{
public:
    set<int> ans;
    int stringToNumber(string s)
    {
        int num = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            int temp = s[i] - '0';
            num = num + (temp * pow(10, s.size() - i - 1));
        }
        return num;
    }

    int getNum(int num1, int num2, int num3)
    {
        string temp1 = "";
        if(num1 != 0)
        {
            temp1 = temp1 + to_string(num1);
            temp1 = temp1 + to_string(num2);
            temp1 = temp1 + to_string(num3);
            return stringToNumber(temp1);
        }
        return -1;
    }
    void help(vector<int> &digits)
    {   
        vector<int> evens(10, -1);
        for (int i = 0; i < digits.size(); i++)
        {
            if((digits[i] & 1) == 0)
            {
                evens[digits[i]] = i;
            }
        }

        for (int i = 0; i < 10; i++)
        {
            if(evens[i] != -1)
            {
                for (int j = 0; j < digits.size() - 1; j++)
                {   
                    if(j == evens[i]) continue;
                    for (int k = j + 1; k < digits.size(); k++)
                    {   
                        if(k == evens[i]) continue;
                        int temp1 = getNum(digits[j], digits[k], i);
                        int temp2 = getNum(digits[k], digits[j], i);
                        if(temp1 != -1)
                        {
                            ans.insert(temp1);
                        }
                        if(temp2 != -1)
                        {
                            ans.insert(temp2);
                        }
                    }
                }
            }
        }
    }

    vector<int> findEvenNumbers(vector<int>& digits) 
    {
        vector<int> ans;
        help(digits);
        for(auto element : Solution :: ans)
        {
            ans.push_back(element);
        }
        return ans;     
    }
};