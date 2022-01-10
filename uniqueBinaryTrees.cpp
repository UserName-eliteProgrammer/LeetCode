#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pb push_back
using namespace std;

// Problem Link ---> https://leetcode.com/problems/unique-binary-search-trees/

class Solution
{
public:
    int numTrees(int n)
    {
        ll dp[20] = {0};
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i] = dp[i] + (dp[j - 1] * dp[i - j]);
            }
        }
        return dp[n];
    }
};

int main()
{
}