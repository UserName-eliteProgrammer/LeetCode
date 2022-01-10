#include <bits/stdc++.h>
using namespace std;
class Solution 
{
public:
	bool help(TreeNode *root)
	{	
        bool b1 = true, b2 = true;
		if(root->left != NULL)
		{	
			if(root->val == root->left->val)
			{	
				b1 = help(root->left);
			}
			else
			{
				return false;
			}
		}
		if(root->right != NULL)
		{	
			if(root->val == root->right->val)
			{	
				b2 = help(root->right);
			}
			else
			{
				return false;
			}
		}
        return b1 and b2;
	}

    bool isUnivalTree(TreeNode* root) 
    {
        return help(root);
    }
};

int main()
{

}