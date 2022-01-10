#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
	TreeNode* createNode(int val)
	{
		TreeNode *node = new TreeNode;
		node->left = NULL;
		node->right = NULL;
		node->val = val;
		return node;
	}

	TreeNode* help(vector<int> &nums, int l, int r)
	{	
		if(l <= r)
        {
            int index = (l + r) / 2;
		    TreeNode* root = createNode(nums[index]);
		    root->left = help(nums, l, index - 1);
		    root->right = help(nums, index + 1, r);
            return root;
        }
        return NULL;
	}

    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {        
        TreeNode *root = help(nums, 0, nums.size() - 1);
        return root;
    }
};


int main()
{

}