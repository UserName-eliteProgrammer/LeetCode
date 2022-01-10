#include <bits/stdc++.h>
using namespace std;

// By BFS 

class Solution
{
public:
	vector<int> ans;
	void help(TreeNode *root)
	{   
		queue<TreeNode *> q;
		q.push(root);
		while(q.size())
		{
			int s = q.size();
			while(s--)
			{
				if(s == 0)
				{
					ans.push_back((q.front())->val);
				}
				if((q.front())->left != NULL)
				{
					q.push(q.front()->left);
				}
				if((q.front())->right != NULL)
				{
					q.push(q.front()->right);
				}
				q.pop();
			}
		}
		return;
	}

    vector<int> rightSideView(TreeNode* root) 
    {   
        if(root == NULL)
        {
            return ans;
        }
        help(root);
        return ans;
    }
};

int main()
{

}class Solution
{
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        
    }
};