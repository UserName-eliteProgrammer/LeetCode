#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
	void swapString(string *s1, string *s2)
	{
		string temp = *s1;
		*s1 = *s2;
		*s2 = temp;
		return;
	}
    string addBinary(string s1, string s2) 
    {
  		string res = "";
  		bool carry = false;
  		int one_count = 0;
  		
  		if(s1.size() < s2.size())
  		{
  			swapString(&s1, &s2);
  		}
        
  		for (int i = s1.size() - 1; i >= (s1.size() - s2.size()); i--)
  		{	
  			one_count = 0;

  			if(s1[i] == '1')
  			{
  				one_count++;
  			}
  			if(s2[i - (s1.size() - s2.size())] == '1')
  			{
  				one_count++;
  			}
  			if(carry)
  			{
  				one_count++;
  			}

  			if(one_count % 2 == 0)
  			{
  				res.push_back('0');
  			}
  			else
  			{
  				res.push_back('1');
  			}

  			if(one_count > 1)
  			{
  				carry = true;
  			}
  			else
  			{
  				carry = false;
  			}
  		}

  		for (int i = (s1.size() - s2.size()) - 1; i >= 0; i--)
  		{	
  			one_count = 0;
  			if(carry)
  			{
  				one_count++;
  			}
  			if(s1[i] == '1')
  			{
  				one_count++;
  			}

  			if(one_count % 2 == 0)
  			{
  				res.push_back('0');
  			}
  			else
  			{
  				res.push_back('1');
  			}

  			if(one_count > 1)
  			{
  				carry = true;
  			}
  			else
  			{
  				carry = false;
  			} 
  		}
        
        if(carry)
        {
            res.push_back('1');
        }

  		reverse(res.begin(), res.end());
  		return res;
    }
};

int main()
{

}