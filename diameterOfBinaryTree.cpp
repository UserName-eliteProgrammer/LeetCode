#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
	int ans = 0;
	map<TreeNode*, int> mp;
	int height(TreeNode* root)
	{
		if(root == NULL)
		{
			return -1;
		}
		if(mp.find(root) != mp.end())
		{
			return mp[root];
		}

		int l, r;
		l = height(root->left);
		r = height(root->right);

		return mp[root] = max(l, r) + 1;
	}

    int diameterOfBinaryTree(TreeNode* root) 
    {	
    	if(root == NULL)
    	{
    		return 0;
    	}

  		int lH = height(root->left);
  		int rH = height(root->right);
        
  		ans = max(ans, lH + rH + 2); // add 2 because of root->left edge and root->right edge contribution
  		diameterOfBinaryTree(root->left);
  		diameterOfBinaryTree(root->right);
  		return ans;
    }
};

int main()
{

}