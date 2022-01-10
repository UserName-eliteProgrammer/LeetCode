#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
	TreeNode *firstNode = NULL, *secondNode = NULL, *prev = NULL;
	void inorderTraversal(TreeNode* root)
	{
		if(root == NULL)
		{
			return;
		}

		inorderTraversal(root->left);
		if(prev != NULL and prev->val > root->val)
		{
			if(firstNode == NULL)
			{
				firstNode = prev;
			}
			secondNode = root;
		}
		prev = root;
		inorderTraversal(root->right);
	}

    void recoverTree(TreeNode* root) 
    {	
    	inorderTraversal(root);
     	int temp = firstNode->val;
     	firstNode->val = secondNode->val;
     	secondNode->val = temp;   
    }
};

int main()
{

}