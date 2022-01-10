class Solution
{
public:
    vector<int> ans;

    TreeNode* findRightMostNode(TreeNode* leftMostNode, TreeNode* curr)
	{
        ans.reserve(100);
		while(leftMostNode->right != NULL and leftMostNode->right != curr)
		{
			leftMostNode = leftMostNode->right;
		}
		return leftMostNode;
	}

    vector<int> inorderTraversal(TreeNode* root)
    {
        TreeNode* curr = root;
		while(curr != NULL)
		{
			TreeNode* leftNode = curr->left;
			if(leftNode == NULL)
			{
				ans.push_back(curr->val);
				curr = curr->right;
			}
			else
			{
				TreeNode* rightMostNode = findRightMostNode(leftNode, curr);
				if(rightMostNode->right == NULL)
				{
					rightMostNode->right = curr;
					curr = curr->left;
				}
				else
				{
					ans.push_back(curr->val);
					curr = curr->right;
					rightMostNode->right = NULL;
				}
			}
		}
		return ans;
	}
};
