#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
	vector<vector<int>> Traversal;
	void change(bool &flag)
	{
		if(flag)
		{
			flag = false;
            return;
		}
		flag = true;
	}
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {	
        if(root == NULL) 
        {
            return Traversal;
        }
           
    	bool flag = true;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size())
        {
        	int s = q.size();
        	vector<int> currLevel;
        	while(s--)
        	{	
        		TreeNode *node = q.front();
                if(node->left != NULL)
                {
                    q.push(node->left);    
                }
        		if(node->right != NULL)
                {
                    q.push(node->right);    
                }
        		currLevel.push_back(node->val);
        		q.pop();
        	}

  
        	if(flag == false)
        	{
        		reverse(currLevel.begin(), currLevel.end());
        	}
        	change(flag);
        	Traversal.push_back(currLevel);
        }
        return Traversal;
    }
};

int main()
{

}