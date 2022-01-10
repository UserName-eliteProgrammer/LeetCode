#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    vector<int> preOrder;
    vector<int> preorderTraversal(TreeNode* root) 
    {   
        if(root == NULL) return preOrder;
        
        stack<TreeNode*> s;
        s.push(root);
        while(s.size())
        {
            TreeNode *node = s.top();
            s.pop();
            if(node->right != NULL)
            {
                s.push(node->right);    
            }
            if(node->left != NULL)
            {
                s.push(node->left);    
            }
            preOrder.push_back(node->val);
        }
        return preOrder;
    }
};

int main()
{

}