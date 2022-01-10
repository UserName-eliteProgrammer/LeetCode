#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pb push_back
using namespace std;

// Problem Link ---> https://leetcode.com/problems/valid-parentheses/

bool isValid(string s)
{
    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '[' or s[i] == '{' or s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (st.size())
        {
            if (s[i] == ')' and st.top() == '(')
            {
                st.pop();
            }
            else if (s[i] == '}' and st.top() == '{')
            {
                st.pop();
            }
            else if (s[i] == ']' and st.top() == '[')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    if (st.size())
    {
        return false;
    }
    return true;
}

int main()
{
}