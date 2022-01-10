#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int counter = 0, ans = 0;
    void rootSum(TreeNode* root, int num, int target)
    {
        if(root == NULL)
        {
            return;    
        }
        if(root->val + num == target)
        {   
            counter++;
        }
        
        if(root->left != NULL)
        {
            rootSum(root->left, num + root->val, target);
        }
        if(root->right != NULL)
        {
            rootSum(root->right, num + root->val, target);    
        }
    }
    
    int pathSum(TreeNode* root, int targetSum) 
    {   
        if(root == NULL)
        {
            return ans;
        }
        
        this->counter = 0;
        rootSum(root, 0, targetSum);
        ans = ans + counter;
        
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        
        return ans;
    }
};

int main()
{

}