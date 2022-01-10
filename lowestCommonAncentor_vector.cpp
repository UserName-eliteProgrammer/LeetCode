#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
	vector<TreeNode*> v1, v2;

	void help(TreeNode *root, TreeNode *target, vector<TreeNode*> &v)
	{
		if(root == NULL)
		{
			return;
		}

		if(root == target)
		{
			v.push_back(root);
			return;
		}

		if(v.empty())
		{
			help(root->left, target, v);
		}
		if(v.empty())
		{
			help(root->right, target, v);
		}

		if(not v.empty())
		{
			v.push_back(root);
		}
		return;
	}

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        help(root, p, v1);
        help(root, q, v2);
        reverse(v1.begin(), v1.end());
        reverse(v2.begin(), v2.end());
 
        TreeNode *ancestor = root;
        for(int i = 0; i < min(v1.size(), v2.size()); i++)
        {
            if(v1[i] == v2[i])
            {
                ancestor = v1[i];
            }
            else
            {
                break;
            }
        }
        return ancestor;
    }
};

int main()
{

}