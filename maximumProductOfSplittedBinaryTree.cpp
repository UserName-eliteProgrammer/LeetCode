class Solution {
public:
    long long int maximum = 0;
    long long int mod = 1000000007;
    unordered_map<TreeNode*, long long int> mp;

    int totalSum(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        if(mp.find(root) != mp.end())
        {
            return mp[root];
        }

        return mp[root] = (root->val) + (totalSum(root->left)) + (totalSum(root->right));
    }

    long long int help(TreeNode* root, long long int sum)
    {
        if(root == NULL)
        {
            return 0;
        }

        long long int ans1, ans2;

        long long int l = totalSum(root->right);
        long long int r = totalSum(root->left);

        ans1 = ((sum - r) * (r));
        ans2 = ((sum - l) * (l));

        this->maximum = (max(ans1, max(this->maximum, ans2)));

        help(root->left, sum);
        help(root->right, sum);
        return 0;
    }

    int maxProduct(TreeNode* root) 
    {
        long long int sum = totalSum(root);
        help(root, sum);
        return (this->maximum) % this->mod;
    }
};