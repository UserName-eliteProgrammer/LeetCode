#include <bits/stdc++.h>
using namespace std;

// problem Link --> https://leetcode.com/problems/group-anagrams/

vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
	unordered_map<string, vector<string>> mp;

	for(int i = 0; i < strs.size(); i++)
	{
		string key = strs[i];
		sort(key.begin(), key.end());
		mp[key].push_back(strs[i]);
	}

	vector<vector<string>> ans;
	for(auto element : mp)
	{
		ans.push_back(element.second);
	}
	return ans;        
}

int main()
{	
	// for testing 

	vector<string> str;
	str.push_back("eat");
	str.push_back("ate");
	str.push_back("tea");
	str.push_back("answer");

	vector<vector<string>> ans;

	ans = groupAnagrams(str);
	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < ans[i].size(); j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}