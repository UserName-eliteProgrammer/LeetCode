#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
    	if(root == NULL or root == p or root == q)
    	{
    		return root;
    	}

    	TreeNode* l = lowestCommonAncestor(root->left, p, q);
    	TreeNode* r = lowestCommonAncestor(root->right, p, q);

    	if(l == NULL)
    	{
    		return r;
    	}
    	else if(r == NULL)
    	{
    		return l;
    	}
    	return root;
    }
};

int main()
{

}