#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pb push_back
using namespace std;

// Problem Link ---> https://leetcode.com/problems/find-the-town-judge/

class Solution
{
public:
    int ans = -1;
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<bool> candidates(n + 1, true);

        for (int j = 0; j < trust.size(); j++)
        {
            candidates[trust[j][0]] = false;
        }

        for (int i = 1; i <= n; i++)
        {

            if (candidates[i])
            {
                int trustiesCount = 0;
                for (int j = 0; j < trust.size(); j++)
                {
                    if (trust[j][1] == i)
                    {
                        trustiesCount++;
                    }
                }

                if (trustiesCount == n - 1)
                {
                    ans = i;
                    break;
                }
            }
        }
        return ans;
    }
};