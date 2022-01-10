#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pb push_back
using namespace std;

// Problem Link ---> https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

// Accepted

int dp[40][1010];

int combinations(int d, int f, int target)
{
    if (target == 0 and d == 0)
    {
        return 1;
    }
    if (d == 0)
    {
        return 0;
    }
    if (dp[d][target] != -1)
    {
        return dp[d][target];
    }

    int ans = 0;
    for (int i = 1; i <= f; i++)
    {
        if (target >= i)
        {
            ans = ((ans % mod) + (combinations(d - 1, f, target - i) % mod)) % mod;
        }
        else
        {
            break;
        }
    }
    return dp[d][target] = ans % mod;
}

int main()
{
    memset(dp, -1, sizeof(dp));
}