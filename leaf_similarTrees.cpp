#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    vector<int> v1, v2;
    void help(TreeNode* root, vector<int> &v)
    {   
        if(root == NULL)
        {
            return;
        }
        if(root->left == NULL and root->right == NULL)
        {
            v.push_back(root->val);
            return;
        }
        
        if(root->left != NULL)
        {
            help(root->left, v);
        }
        if(root->right != NULL)
        {
            help(root->right, v);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {   
        help(root1, v1);
        help(root2, v2);
        if(v1.size() != v2.size())
        {
            return false;
        }
        for(int i = 0; i < v1.size(); i++)
        {
            if(v1[i] != v2[i])
            {
                return false;
            }
        }
        return true;
    }
};


int main()
{
    
}