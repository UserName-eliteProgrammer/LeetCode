#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:

	TreeNode* buildTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &inMap)
	{	
		if(preStart > preEnd or inStart > inEnd)
		{
			return NULL;
		}

		TreeNode *root = new TreeNode(preorder[preStart]);
		int inRootIndex = inMap[preorder[preStart]];
		int numsLeft = inRootIndex - inStart;

		root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRootIndex - 1, inMap);

		root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRootIndex + 1, inEnd, inMap);

		return root;
	}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
    	map<int ,int> inMap;
    	for (int i = 0; i < inorder.size(); i++)
    	{
    		inMap[inorder[i]] = i;
    	}
    	return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
    }
};

int main()
{

}