#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
	vector<int> ans;

	void help(Node *root)
	{	
		for (int i = 0; i < (root->children).size(); i++)
		{
			help(root->children[i]);
		}
		ans.push_back(root->val);
	}
    vector<int> postorder(Node* root) 
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

}