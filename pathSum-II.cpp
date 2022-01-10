#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> ans;
    vector<int> path;
    void help(TreeNode* root, int target, int sum)
    {   
        if(root == NULL)
        {
            return;
        }
        
        if(sum + root->val == target and root->left == NULL and root->right == NULL)
        {   
            path.push_back(root->val);
            ans.push_back(path);
            path.pop_back();
            return;
        }
       
        path.push_back(root->val);
        help(root->left, target, sum + root->val);
        help(root->right, target, sum + root->val); 
        path.pop_back();   
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {   
        help(root, targetSum, 0);
        return ans;
    }
};

int main()
{

}