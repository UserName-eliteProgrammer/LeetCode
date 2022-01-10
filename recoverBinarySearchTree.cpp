#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    
    TreeNode* findRightMostNode(TreeNode* node, TreeNode* parent)
	{
		while(node->right != NULL and node->right != parent)
		{
			node = node->right;
		}
		return node;
	}
    
	void morrisInorderTraversal(TreeNode* root)
	{
		TreeNode* firstNode = NULL;
        TreeNode* secondNode = NULL;
        TreeNode* prev = NULL;
		TreeNode* currNode = root;

		while(currNode != NULL)
		{
			TreeNode* leftNode = currNode->left;
			if(leftNode == NULL)
			{	
                if(prev != NULL and prev->val  > currNode->val)
				{	
					if(firstNode == NULL)
					{
						firstNode = prev;
					}
					secondNode = currNode;
				}    	
				prev = currNode;
				currNode = currNode->right;
			}
			else
			{
				TreeNode* rightMostNode = findRightMostNode(leftNode, currNode);
				if(rightMostNode->right == NULL)
				{
					rightMostNode->right = currNode;
					currNode = currNode->left;
				}
				else
				{	
					if(prev->val  > currNode->val)
					{	
						if(firstNode == NULL)
						{
							firstNode = prev;
						}
						secondNode = currNode;
					}
					prev = currNode;
					currNode = currNode->right;
					rightMostNode->right = NULL;
				}	
			}
		}
        
		int temp = secondNode->val;
		secondNode->val = firstNode->val;
		firstNode->val = temp;
        
		return;
	}

    void recoverTree(TreeNode* root) 
    {   
    	morrisInorderTraversal(root);
    	return;
    }
};

int main()
{

}