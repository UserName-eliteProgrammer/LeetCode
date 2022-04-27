class Solution 
{
private:
    TreeNode* ans = NULL;
    void help(TreeNode* root, TreeNode* p, TreeNode* q)
    {   
        if(ans != NULL) return;
        if(root == NULL) return;
        
        if(p->val <= root->val and q->val >= root->val)
        {   
            ans = root;
            return;
        }
        help(root->left, p, q);
        help(root->right, p, q);
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {   
        if(p->val < q->val)
        {   
            help(root, p, q);    
        }
        else
        {
            help(root, q, p);
        }
        return ans;
    }
};