#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pb push_back
using namespace std;

// Problem Link --->

class Solution
{
public:
    set<string> s;
    bool help(string s1, string s2, int pos)
    {
        if (pos >= s2.size())
        {
            return true;
        }
        for (int i = pos; i < s2.size(); i++)
        {
            if (this->s.find(s1 + s2[i]) != this->s.end())
            {
                if (help("", s2, i + 1))
                {
                    return true;
                }
            }
            s1 = s1 + s2[i];
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