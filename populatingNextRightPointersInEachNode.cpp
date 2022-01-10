#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
	void bfs(Node* root)
	{
		queue<Node*> qu;
		qu.push(root);
		while(qu.size())
		{
			int levelSize = qu.size();
			while(levelSize--)
			{	
				Node* currNode = qu.front();
				qu.pop();

				if(levelSize == 0)
				{
					currNode->next = NULL;
				}
				else
				{	
					currNode->next = qu.front();
				}

				if(currNode->left != NULL)
				{
					qu.push(currNode->left);
				}
				if(currNode->right != NULL)
				{
					qu.push(currNode->right);
				}
			}
		}
		return;
	}

    Node* connect(Node* root) 
    {   
        if(root == NULL) return NULL;
  		bfs(root);
  		return root;		      
    }
};

int main()
{

}