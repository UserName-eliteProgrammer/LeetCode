#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
	int ans = 0;
    int widthOfBinaryTree(TreeNode* root) 
    {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(q.size())
        {
        	int s = q.size();
            int levelMin = q.front().second;
            ans = max(ans, (q.back().second - q.front().second) + 1);
        	while(s--)
        	{   
                TreeNode* node = q.front().first;
        		if(node->left != NULL)
	        	{
	        		long long int index = (2 * (q.front().second - levelMin)) + 1;
	        		q.push({node->left, index});
	        	}
	        	if(node->right != NULL)
	        	{
	        		long long int index = (2 * (q.front().second - levelMin)) + 2;
	        		q.push({node->right, index});
	        	}
	        	q.pop();	
            }	
        }
        return ans;
    }
};

int main()
{

}