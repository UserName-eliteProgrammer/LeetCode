class Solution 
{
private:
    int findSum(TreeNode* root, int *ans)
    {
        if(root == NULL)
        {
            return 0;
        }

        int leftSum = findSum(root->left, ans);
        int rightSum = findSum(root->right, ans);
        *ans = *ans + abs(leftSum - rightSum);
        return leftSum + root->val + rightSum;
    }
    
public:
    int findTilt(TreeNode* root) 
    {   
        int ans = 0;
        findSum(root, &ans); 
        return ans;     
    }
};