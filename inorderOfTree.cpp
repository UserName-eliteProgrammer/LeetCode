#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
	vector<int> ans;

	void help(TreeNode *root)
	{
		if(root == NULL)
		{
			return;
		}
		help(root->left);
		ans.push_back(root->val);
		help(root->right);
	}

    vector<int> inorderTraversal(TreeNode* root) 
    {
   		ans.reserve(100);
   		help(root);
   		return ans;
    }
};

int main()
{

}