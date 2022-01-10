#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
	vector<int> ans;

	void help(TreeNode* root)
	{
		if(root == NULL)
		{
			return;
		}
		ans.push_back(root->val);
		help(root->left);
		help(root->right);
	}

    vector<int> preorderTraversal(TreeNode* root) 
    {
        help(root);
        return ans;
    }
};

int main()
{

}