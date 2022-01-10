#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
	int ans = 0;
	void help(TreeNode* root, int low, int high)
	{	
		if(root == NULL)
		{
			return;
		}

		if(root->val >= low and root->val <= high)
		{
			ans += root->val;
			help(root->left, low, high);
			help(root->right, low, high);
		}
		else if(root->val < low)
		{
			help(root->right, low, high);
		}
		else if(root->val > high)
		{
			help(root->left, low, high);
		}
		return;
	}

    int rangeSumBST(TreeNode* root, int low, int high) 
    {
    	help(root, low, high);
    	return ans;      
    }
};

int main()
{

}