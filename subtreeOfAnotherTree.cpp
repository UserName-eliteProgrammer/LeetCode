#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
	bool isSame(TreeNode *root1, TreeNode *root2)
	{
		if(root1 == NULL and root2 == NULL)
		{
			return true;
		}
		if((root1 == NULL and root2 != NULL) or (root2 == NULL and root1 != NULL))
		{
			return false;
		}

		if(root1->val == root2->val)
		{
			return isSame(root1->left, root2->left) and isSame(root1->right, root2->right);
		}
		else
		{
			return false;
		}
	}
	

    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {	
    	if(root == NULL)
        {
            return false;    
        }

    	if(isSame(root, subRoot))
    	{
    		return true;
    	}
        return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }
};

int main()
{

}