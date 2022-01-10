#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pb push_back
using namespace std;

// Problem Link ---> https://leetcode.com/problems/word-break/

class Solution
{
public:
    set<string> s;
    unordered_map<int, bool> dp;
    bool help(string s1, string s2, int pos)
    {
        if (pos >= s2.size())
        {
            return true;
        }

        if (dp.find(pos) != dp.end())
        {
            return dp[pos];
        }
        for (int i = pos; i < s2.size(); i++)
        {
            if (this->s.find(s1 + s2[i]) != this->s.end())
            {
                if (help("", s2, i + 1))
                {
                    dp[i + 1] = true;
                    return true;
                }
                else
                {
                    dp[i + 1] = false;
                }
            }
            s1.push_back(s2[i]);
        }
        return false;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        for (int i = 0; i < wordDict.size(); i++)
        {
            this->s.insert(wordDict[i]);
        }
        return help("", s, 0);
    }
};

int main()
{
}