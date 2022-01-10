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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<pair<TreeNode *, int>> q1;
        vector<vector<int>> ans;
        vector<int> levelNodes;
        int currLevel = 0;
        (root != NULL) ? q1.push(make_pair(root, 0)) : levelNodes.clear();
        while (!q1.empty())
        {
            TreeNode *node = q1.front().first;
            if (node->left != NULL)
            {
                q1.push(make_pair(node->left, q1.front().second + 1));
            }
            if (node->right != NULL)
            {
                q1.push(make_pair(node->right, q1.front().second + 1));
            }

            if (currLevel != q1.front().second)
            {
                currLevel++;
                ans.push_back(levelNodes);
                levelNodes.clear();
            }
            levelNodes.push_back(node->val);
            q1.pop();
        }
        (levelNodes.empty()) ? ans.clear() : ans.push_back(levelNodes);
        return ans;
    }
};

int main()
{
}