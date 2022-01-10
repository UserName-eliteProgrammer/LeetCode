#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
	vector<vector<int>> BFS;
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {	
    	if(root == NULL)
    	{
    		return BFS;
    	}
    	
    	queue<TreeNode*> q;
    	q.push(root);
    	while(q.size())
    	{	
    		int s = q.size();
    		vector<int> level;
    		while(s--)
    		{
    			level.push_back(q.front()->val);
    			if(q.front()->left != NULL)
    			{
    				q.push(q.front()->left);
    			}
    			if(q.front()->right != NULL)
    			{
    				q.push(q.front()->right);
    			}
    			q.pop();
    		}
    		BFS.push_back(level);
    	}
    	reverse(BFS.begin(), BFS.end());
    	return BFS;               
    }
};

int main()
{

}