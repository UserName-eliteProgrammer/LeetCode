class Solution 
{
private:
    TreeNode* help(TreeNode* root1, TreeNode* root2, TreeNode* target)
    {
        if(root1 == NULL) return NULL;
        if(root1 == target) return root2;

        TreeNode* temp1 =  help(root1->left, root2->left, target);
        TreeNode* temp2 = help(root1->right, root2->right, target);
        return temp1 != NULL ? temp1 : temp2;
    }

public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
    {
        return help(original, cloned, target);
    }
};