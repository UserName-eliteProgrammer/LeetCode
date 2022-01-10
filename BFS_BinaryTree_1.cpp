#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pb push_back
using namespace std;

// Problem Link ---> https://leetcode.com/problems/binary-tree-level-order-traversal/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution
{
public:
    void traversal(TreeNode *root, int currHeight, int level, vector<int> &levelNodes)
    {
        if (root == NULL)
        {
            return;
        }
        if (currHeight == level)
        {
            levelNodes.push_back(root->val);
            return;
        }
        traversal(root->left, currHeight + 1, level, levelNodes);
        traversal(root->right, currHeight + 1, level, levelNodes);
    }

    int height(TreeNode *root)
    {
        if (root == NULL)
        {
            return -1;
        }
        int h1 = height(root->left);
        int h2 = height(root->right);
        return max(h1, h2) + 1;
    }
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        int h = height(root);
        vector<vector<int>> ans;
        for (int i = 0; i <= h; i++)
        {
            vector<int> levelNodes;
            traversal(root, 0, i, levelNodes);
            ans.push_back(levelNodes);
        }
        return ans;
    }
};

int main()
{
}