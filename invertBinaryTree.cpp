#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pb push_back
using namespace std;

// Problem Link --->

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution
{
public:
    void help(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        help(root->left);
        help(root->right);
    }

    TreeNode *invertTree(TreeNode *root)
    {
        help(root);
        return root;
    }
};

int main()
{
}