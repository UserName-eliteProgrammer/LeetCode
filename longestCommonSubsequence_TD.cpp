#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pb push_back
using namespace std;

static int dp[1001][1001];

int help(string s1, string s2, int index1, int index2)
{
    if (index1 < 0 or index2 < 0)
    {
        return 0;
    }
    if (not dp[index1][index2] == -1)
    {
        return dp[index1][index2];
    }

    if (s1[index1] == s2[index2])
    {
        return dp[index1][index2] = 1 + help(s1, s2, index1 - 1, index2 - 1);
    }
    else
    {
        return dp[index1][index2] = max(help(s1, s2, index1 - 1, index2), help(s1, s2, index1, index2 - 1));
    }
}

int longestCommonSubsequence(string s1, string s2)
{
    memset(dp, -1, sizeof(dp));
    return help(s1, s2, s1.size() - 1, s2.size() - 1);
}

int main()
{
}