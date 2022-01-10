#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
	int maxi = INT32_MIN;
	void findMax(TreeNode *root)
	{	
		if(root == NULL)
		{
			return;
		}
        
		if(root->val > maxi)
		{
			maxi = root->val;
		}
		findMax(root->right);
		findMax(root->left);
	}
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(root == NULL)
        {
            return NULL;
        }
		if(root->val > key)
		{
			root->left = deleteNode(root->left, key);	
		}        
		else if(root->val < key)
		{
			root->right = deleteNode(root->right, key);
		}
		else
		{
			if(root->left == NULL and root->right == NULL)
			{	
				delete root;
				return NULL;
			}
			else if(root->left == NULL)
			{
				TreeNode *temp = root;
				root = root->right;
				delete temp;
				return root;
			}
			else if(root->right == NULL)
			{
				TreeNode *temp = root;
				root = root->left;
				delete temp;
				return root;
			}
			else
			{
				maxi = INT32_MIN;
				findMax(root->left);
				root->val = maxi;
				root->left = deleteNode(root->left, maxi);
			}
		}
		return root;
    }
};

int main()
{

}