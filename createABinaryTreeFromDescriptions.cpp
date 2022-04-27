class Solution 
{
private:
    TreeNode *createNode(int num)
    {
        TreeNode* node = new TreeNode;
        node->left = NULL;
        node->right = NULL;
        node->val = num;
        return node;
    }
    

    TreeNode* help(vector<vector<int>>& arr)
    {   
        TreeNode* root;
        map<TreeNode*, TreeNode*> childParent;
        map<int, TreeNode*> mp;
        for (int i = 0; i < arr.size(); i++)
        {   
            if(mp.find(arr[i][0]) != mp.end() and mp.find(arr[i][1]) != mp.end()) // both
            {
                if(arr[i][2] == 1)
                {
                    mp[arr[i][0]]->left = mp[arr[i][1]];
                }
                else
                {
                    mp[arr[i][0]]->right = mp[arr[i][1]];   
                }
                childParent[mp[arr[i][1]]] = mp[arr[i][0]]; 
            } 
            else if(mp.find(arr[i][0]) != mp.end()) // parent
            {
                TreeNode* child = createNode(arr[i][1]);
                if (arr[i][2] == 1)
                {
                    mp[arr[i][0]]->left = child;
                }
                else
                {
                    mp[arr[i][0]]->right = child;
                }
                mp[arr[i][1]] = child;
                childParent[child] = mp[arr[i][0]];
            }
            else if(mp.find(arr[i][1]) != mp.end()) // child
            {
                TreeNode* parent = createNode(arr[i][0]);
                if(arr[i][2] == 1)
                {
                    parent->left = mp[arr[i][1]];
                }
                else
                {
                    parent->right = mp[arr[i][1]];
                }
                mp[arr[i][0]] = parent;
                childParent[parent] = NULL;
                childParent[mp[arr[i][1]]] = parent;
            }
            else
            {
                TreeNode* parent = createNode(arr[i][0]);
                TreeNode* child = createNode(arr[i][1]);
                if(arr[i][2] == 1)
                {
                    parent->left = child;
                }
                else
                {
                    parent->right = child;
                }
                mp[arr[i][0]] = parent;
                mp[arr[i][1]] = child;
                childParent[child] = parent;
                childParent[parent] = NULL;
            }
        }

        for(auto it : childParent)
        {
            if(it.second == NULL)
            {
                root = it.first;
                break;
            }
        }
        return root;
    }

public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) 
    {
        return help(descriptions);   
    }
};