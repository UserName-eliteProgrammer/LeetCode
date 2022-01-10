#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    bool flag = true;
    long long int prev = INT64_MIN;

    void help(TreeNode* root)
    {	
    	if(root == NULL or flag == false)
    	{
    		return;
    	}

    	help(root->left);
    	if(prev < root->val)
    	{
    		prev = root->val;
    	}
    	else
    	{   
    		flag = false;
    	}
    	help(root->right);
    }

    bool isValidBST(TreeNode* root) 
    {
        help(root);
        return flag;
    }
};


int main()
{

}