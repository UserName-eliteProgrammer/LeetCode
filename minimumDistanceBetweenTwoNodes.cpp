#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
	vector<int> inorderArr;

	void inorderTraversal(TreeNode *root)
	{
		if(root == NULL)
		{
			return;
		}

		inorderTraversal(root->left);
		inorderArr.push_back(root->val);
		inorderTraversal(root->right);
	}

    int minDiffInBST(TreeNode* root) 
    {   
        inorderTraversal(root);
        int ans = INT32_MAX;
        for (int i = 1; i < inorderArr.size(); i++)
        {
        	ans = min(ans, inorderArr[i] - inorderArr[i-1]);
        }
        return ans;
    }
};


int main()
{

}