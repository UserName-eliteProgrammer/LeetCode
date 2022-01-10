#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    map<TreeNode*, TreeNode*> mp;
    vector<int> ans;

    void fillMap(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);
        mp[root] = NULL;
        while(q.size())
        {
            TreeNode* parent = q.front();
            if(parent->left != NULL)
            {
                q.push(parent->left);
                mp[parent->left] = parent;
            }
            if(parent->right != NULL)
            {
                q.push(parent->right);
                mp[parent->right] = parent;
            }
            q.pop();
        }
        return;    
    }

    void help(TreeNode* node, int k, int currDis, map<TreeNode*, bool> &visited)
    {
        if(node == NULL)
        {
            return;
        }
        if(visited[node] == true)
        {
            return;
        }
        if(currDis == k)
        {
            ans.push_back(node->val);
            return;
        }

        visited[node] = true;
        help(mp[node], k, currDis + 1, visited);
        help(node->right, k, currDis + 1, visited);
        help(node->left, k, currDis + 1, visited);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {   
        map<TreeNode*, bool> visited;
        fillMap(root);
        help(target, k, 0, visited);
        return ans;
    }
};
