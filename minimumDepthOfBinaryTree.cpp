#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
	int help(TreeNode* root)
	{
		if(root == NULL)
		{
			return 0;
		}

		int l = INT16_MAX, r = INT16_MAX;
		if(root->left != NULL)
		{
			l = help(root->left);	
		}
		if(root->right != NULL)
		{
			r = help(root->right);
		}
        if(root->left == NULL and root->right == NULL)
        {
            return 1;
        }
		return min(l, r) + 1;
	}

    int minDepth(TreeNode* root) 
    {
        return help(root);
    }
};


int main()
{

}