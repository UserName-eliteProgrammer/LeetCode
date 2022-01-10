#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
	vector<int> inorderArr;
	void inorderTraversal(TreeNode *root, int k)
	{
		if(root == NULL)
		{
			return;
		}
		if(inorderArr.size() == k)
		{
			return;
		}
		
		inorderTraversal(root->left, k);
		if(inorderArr.size() < k)
		{
			inorderArr.push_back(root->val);
		}
		inorderTraversal(root->right, k);
	}
	
    int kthSmallest(TreeNode* root, int k) 
    {
    	inorderTraversal(root, k);
    	return inorderArr[k - 1];
    }
};

int main()
{

}