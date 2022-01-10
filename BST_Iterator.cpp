#include<bits/stdc++.h>
using namespace std;

class BSTIterator 
{
public:
	stack<TreeNode*> s;
	void allLeft(TreeNode *root)
	{
		while(root != NULL)
		{
			s.push(root);
			root = root->left;
		}
		return;
	}
    
    BSTIterator(TreeNode* root) 
    {
  		allLeft(root);
    }
    
    int next() 
    {
        TreeNode* node = s.top();
        s.pop();
        allLeft(node->right);
        return node->val;
    }
    
    bool hasNext() 
    {
        return s.size();
    }
};

int main()
{

}