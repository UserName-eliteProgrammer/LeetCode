#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
	bool help(TreeNode* root1, TreeNode* root2)
	{
		if((root1 == NULL and root2 != NULL) or (root2 == NULL and root1 != NULL))
		{
			return false;
		}
		if(root1 == NULL and root2 == NULL)
		{
			return true;
		}

		bool b1, b2;
		if(root1->val == root2->val)
		{
			b1 = help(root1->left, root2->right);
			b2 = help(root1->right, root2->left); 
		}
		else
		{
			return false;
		}
		
		return b1 and b2;
	}

    bool isSymmetric(TreeNode* root) 
    {
		return help(root->left, root->right); 
    }
};


int main()
{

}