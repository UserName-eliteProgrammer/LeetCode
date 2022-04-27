class Solution 
{
private:
    vector<int> nodes, prefix;
    void inorderTraversal(TreeNode *itr)
    {
        if(itr == NULL) return;
        
        inorderTraversal(itr->left);
        nodes.push_back(itr->val);
        inorderTraversal(itr->right);
    }
    
    void builtPrefix()
    {   
        prefix.resize(nodes.size());
        prefix[0] = nodes[0];
        for(int i = 1; i < nodes.size(); i++)
        {
            prefix[i] = prefix[i - 1] + nodes[i];
        }
    }
    
    int search(int target)
    {
        int l = 0, h = nodes.size() - 1;
        while(l <= h)
        {
            int m = h - ((h - l) / 2);
            if(nodes[m] == target) return m;
            else if(nodes[m] > target) h = m - 1;
            else l = m + 1;
        }
        return -1;
    }
    
    void updateTree(TreeNode* itr)
    {
        if(itr == NULL) return;
        
        nodes.reserve(500);
        int index = search(itr->val);
        itr->val += prefix[prefix.size() - 1] - prefix[index];
        updateTree(itr->left);
        updateTree(itr->right);
    }
    
public:
    TreeNode* convertBST(TreeNode* root) 
    {   
        if(root == NULL) return NULL;
        inorderTraversal(root);
        builtPrefix();
        updateTree(root);
        return root;
    }
};