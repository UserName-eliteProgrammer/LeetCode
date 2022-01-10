#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
	vector<vector<int>> BFS;
	void help(Node *root)
	{
		queue<Node*> q;
		q.push(root);
		while(q.size())
		{
			int s = q.size();
			vector<int> currLevel;
			while(s--)
			{	
				Node* node = q.front();
				currLevel.push_back(node->val);
				for(auto ch : node->children)
				{
					q.push(ch);
				}
				q.pop();
			}
			BFS.push_back(currLevel);
		}
		return;
	}
    vector<vector<int>> levelOrder(Node* root) 
    {
        if(root == NULL)
        {
        	return BFS;
        }
        help(root);
        return BFS;
    }
};

int main()
{

}