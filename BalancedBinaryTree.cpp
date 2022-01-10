#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
	map<TreeNode*, pair<int, int>> mp;
	int height(TreeNode *root)
	{
		if(root == NULL)
		{
			return -1;
		}
		if(mp.find(root) != mp.end())
		{
			return max(mp[root].first, mp[root].second) + 1;
		}

		int l = height(root->left);
		int r = height(root->right);

		mp[root].first = l;
		mp[root].second = r;
		return max(l, r) + 1;
	}


    bool isBalanced(TreeNode* root) 
    {
		if(root == NULL)
		{
			return true;
		}

		int bf = height(root->right) - height(root->left);

		if(abs(bf) <= 1)
		{
			return isBalanced(root->right) and isBalanced(root->left); 
		}
		return false;     
    }
};


int main()
{

}