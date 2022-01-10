class Solution 
{
public:

    TreeNode* createNode()
    {
        TreeNode *newNode = new TreeNode;
        newNode->right = NULL;
        newNode->left = NULL;
        return newNode;
    }

    void insert(TreeNode *root, int val)
    {
        if(root == NULL)
        {   
            TreeNode* newNode = createNode();
            newNode->val = val;
            return;
        }
        if(root->val < val)
        {   
            if(root->right == NULL)
            {
                TreeNode* newNode = createNode();
                newNode->val = val;
                return;
            }
            insert(root->right, val);
        }
        if(root->val > val)
        {
           if(root->left == NULL)
           {
                TreeNode* newNode = createNode();
                newNode->val = val;
                return;
           }
           insert(root->left, val);
        }
        return;
    }

    vector<TreeNode*> generateTrees(int n) 
    {   
        vector<TreeNode *> ans;
        int num = 1;
        while(num <= n)
        {   
            TreeNode *tempRoot = new TreeNode;
            tempRoot->val = num;
            tempRoot->right = NULL;
            tempRoot->right = NULL;

            for(int i = 1; i < num; i++)
            {
                insert(tempRoot, i);
            }
            for(int i = num + 1; i <= n; i++)
            {
                insert(tempRoot, i);
            }
            ans.push_back(tempRoot);
            num++;
        }
        return ans;    
    }
};