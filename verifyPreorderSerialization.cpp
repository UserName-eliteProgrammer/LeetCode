#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pb push_back
using namespace std;

// Problem Link ---> https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/

class Solution
{
public:
    bool isValidSerialization(string preorder)
    {
        int vancany = 1;
        for (int i = 0; i < preorder.size(); i++)
        {
            if (vancany == 0 and i < preorder.size() - 1)
            {
                return false;
            }

            if (preorder[i] == ',')
            {
                continue;
            }
            else if (preorder[i] == '#')
            {
                vancany--;
            }
            else
            {
                while (preorder[i] != ',' and i < preorder.size())
                {
                    i++;
                }
                vancany = vancany + 1;
            }
        }
        if (vancany == 0)
        {
            return true;
        }
        return false;
    }
};

int main()
{
}