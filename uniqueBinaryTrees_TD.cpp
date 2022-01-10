#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pb push_back
using namespace std;

// Problem Link ---> https://leetcode.com/problems/unique-binary-search-trees/

class Solution
{
public:
    int dp[20];
    int help(int n)
    {
        if (n == 0 or n == 1)
        {
            return 1;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }

        long long int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            dp[i - 1] = help(i - 1);
            dp[n - i] = help(n - i);
            ans = ans + (dp[i - 1] * dp[n - i]);
        }
        return dp[n] = ans;
    }

    int numTrees(int n)
    {
        memset(dp, -1, sizeof(dp));
        return help(n);
    }
};

int main()
{
}