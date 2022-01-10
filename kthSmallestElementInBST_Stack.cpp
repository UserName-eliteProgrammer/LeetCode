#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
	stack<TreeNode*> s;
	void addLeft(TreeNode* root)
	{
		while(root != NULL)
		{
			s.push(root);
			root = root->left;
		}
	}
    int kthSmallest(TreeNode* root, int k) 
    {
        addLeft(root);
        while(k--)
        {	
        	if(k == 0)
        	{
        		break;
        	}
        	
        	TreeNode *node = s.top();
        	s.pop();
        	addLeft(root->right);
        }
        return s.top()->val;
    }
};

int main()
{

}