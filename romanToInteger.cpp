#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
	map<char, int> mp;
	
	void setMap()
	{
		mp['I'] = 1;
		mp['V'] = 5;
		mp['X'] = 10;
		mp['L'] = 50;
		mp['C'] = 100;
		mp['D'] = 500;
		mp['M'] = 1000;

		return;
	}

    int romanToInt(string s) 
    {	
    	setMap();
    	
    	int ans = 0, prev = mp[s[s.size() - 1]];
    	ans = ans + prev;

        for (int i = s.size() - 2; i >= 0; i--)
        {
        	if(mp[s[i]] < prev)
        	{
        		ans = ans - mp[s[i]];
        	}	
        	else
        	{
        		ans = ans + mp[s[i]];
        	}
            
            prev = mp[s[i]];
        }
        return ans;
    }
};

int main()
{

}