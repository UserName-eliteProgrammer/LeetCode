#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pb push_back
using namespace std;

// Problem Link ---> https://leetcode.com/problems/unique-binary-search-trees/

class Solution
{
public:
    int help(int n)
    {
        if (n == 0 or n == 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 2;
        }

        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans = ans + (help(i - 1) * help(n - i));
        }
        return ans;
    }

    int numTrees(int n)
    {
        return help(n);
    }
};

int main()
{
}