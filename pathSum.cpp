class Solution 
{
private:
    bool help(TreeNode* node, int targetSum)
    {   
        if(node == NULL)
        {
            return false;
        }
        if(node->left == NULL and node->right == NULL and targetSum - node->val == 0)
        {
            return true;
        }
        
        if(help(node->left, targetSum - node->val)) return true;
        bool temp1 = help(node->right, targetSum - node->val);
        return temp1;
    
    }
    
public:
    bool hasPathSum(TreeNode* node, int targetSum) 
    {   
        if(node == NULL) return false;
        return help(node, targetSum);
    }
};