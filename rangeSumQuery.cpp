#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
	int sum = 0;

	void help(TreeNode* root, int low, int high) 
    {
  		if(root == NULL) return;

  		if(root->val >= low and root->val <= high)
  		{
  			sum += root->val;
  		}
  		help(root->left, low, high);
  		help(root->right, low, high);
  		return;      
    }

    int rangeSumBST(TreeNode* root, int low, int high) 
    {
  		help(root, low, high);
  		return sum;
    }
};

int main()
{

}