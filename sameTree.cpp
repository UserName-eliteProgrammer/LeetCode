#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(p == NULL and q == NULL)
        {
        	return true;
        }
        if((p == NULL and q != NULL) or (q == NULL and p != NULL))
        {
            return false;
        }

        bool l = true, r = true;
        if(p->val == q->val)
        {	
        	if(p->left != NULL and q->left != NULL)
        	{
        		l = isSameTree(p->left, q->left);	
        	}
        	else if((p->left == NULL or q->left == NULL) and (p->left != q->left))
        	{   
        		return l = false;
        	}
        	
        	if(p->right != NULL and q->right != NULL)
        	{
        		r = isSameTree(p->right, q->right);
        	}
        	else if((p->right == NULL or q->right == NULL) and (p->right != q->right))
        	{
        		return r = false;
        	}	
        }
        else
        {
        	return false;
        }
        return l and r;
    }
};

int main()
{

}