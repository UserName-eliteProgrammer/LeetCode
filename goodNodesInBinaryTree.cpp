#include <bits/stdc++.h>
using namespace std;

int help(TreeNode * root, int maxi)
{
	if(root == NULL)
	{
		return 0;
	}
	int newMax = max(root->val, maxi);
	if (root->val >= newMax)
	{
	 	return 1 + help(root->right, newMax) + help(root->left, newMax);
	}
	else
	{
		return help(root->right, newMax) + help(root->left, newMax);	
	}
}

int goodNodes(TreeNode* root) 
{	
	return help(root, INT16_MIN);
}

int main()
{

}