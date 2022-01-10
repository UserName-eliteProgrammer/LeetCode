#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
	vector<string> s;

    vector<string> binaryTreePaths(TreeNode* root, string osf = "") 
    {	
    	if(root == NULL)
    	{
    		return s;
    	}
        if(root->left == NULL and root->right == NULL)
        {
        	s.push_back(osf + to_string(root->val));
        	return s;
        }

        if(root->left != NULL)
        {
        	binaryTreePaths(root->left, osf + to_string(root->val) + "->");
        }
        if(root->right != NULL)
        {
        	binaryTreePaths(root->right, osf + to_string(root->val) + "->");	
        }
        return s;
    }
};

int main()
{

}